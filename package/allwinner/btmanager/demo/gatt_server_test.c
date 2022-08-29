#include <stdio.h>
#include <poll.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <sys/signalfd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "log.h"
#include "bt_adv.h"
#include "bt_gatt_server.h"

#define TEST_SERVICE_UUID    "1112"
#define TEST_CHAR_UUID1      "2223"
#define TEST_CHAR_UUID2      "3334"

#define TEST_DESC_UUID      "00006666-0000-1000-8000-00805F9B34FB"

static uint16_t service_handle;


static int __main_terminated;

#define LOG_BUF_MAX_LEN	256
static char log_buf[LOG_BUF_MAX_LEN];

static void print_prompt(void)
{
	printf("[gatt test]# ");
	fflush(stdout);
}

static void rtb_printf(const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	vsnprintf(log_buf, sizeof(log_buf), fmt, args);
	va_end(args);

	printf("%s", log_buf);
	print_prompt();
}

static int parse_arguments(char *arguments, char **argv)
{
	int argc;
	char *p;
	char *parg = (char *)arguments;

	if (!arguments || !argv)
		return 0;

	argc = 0;
	while ((p = strsep(&parg, " \t")))
		if (p[0])
			argv[argc++] = p;

	return argc;
}

void bt_gatt_connection_cb(tGattConnectionEvent event)
{
	if(event == BT_GATT_CONNECTION) {
		printf("gatt server connected.\n");
	} else if(event == BT_GATT_DISCONNECT) {
		printf("gatt server disconnected.\n");
	} else {
		printf("gatt server event unkown.\n");
	}

}

void bt_gatt_add_service_cb(tGattAddSvcMsg *msg)
{
	if(msg != NULL) {
		service_handle = msg->svc_handle;
		printf("service handle is %d\n",service_handle);
	}

}

static int char_handle;
void bt_gatt_add_char_cb(tGattAddCharMsg *msg)
{
	if(msg != NULL) {
		printf("char uuid: %s,chr handle is %d\n",msg->uuid,msg->char_handle);
		char_handle = msg->char_handle;
	}
}

void bt_gatt_add_desc_cb(tGattAddDescMsg *msg)
{
	if(msg != NULL) {
		printf("service handle is %d\n", msg->desc_handle);
	}

}

void bt_gatt_char_read_request_cb(tGattCharReadReq *chr_read)
{
	pr_info("enter");
	char value[1];
	static unsigned char count = 0;

	pr_info("trans_id:%d,attr_handle:%d,offset:%d",chr_read->trans_id,
		chr_read->attr_handle,chr_read->offset);

	if(chr_read) {
		tGattSendReadRsp data;
		data.trans_id = chr_read->trans_id;
		data.svc_handle = chr_read->attr_handle;
		data.status = 0x0b;
		data.auth_req = 0x00;
		value[0]= count;
		data.value = value;
		data.value_len = 1;
		bt_gatt_send_read_response(&data);
		count ++;
	}
}
void bt_gatt_send_indication_cb(tGattSendIndication *send_ind)
{
	pr_info("enter");
}

static void hex_dump(char *pref, int width, unsigned char *buf, int len)
{
	int i,n;
    for (i = 0, n = 1; i < len; i++, n++){
        if (n == 1)
            printf("%s", pref);
        printf("%2.2X ", buf[i]);
        if (n == width) {
            printf("\n");
            n = 0;
        }
    }
    if (i && n!=1)
        printf("\n");
}


void bt_gatt_char_write_request_cb(tGattCharWriteReq *char_write)
{
	pr_info("enter");
	static unsigned char data_value[1] = {0};
	if(char_write) {
		pr_info("handle: %d,tran_id: %d\n",char_write->attr_handle,
			char_write->trans_id);
		pr_info("Value:");
		hex_dump(" ", 20,char_write->value,char_write->value_len);
	}

	tGattNotifyRsp data;
	data.attr_handle = char_write->attr_handle;
	data.value = data_value;
	data.value_len = 1;

	data_value[0] ++ ;
	pr_info("send data value:%d\n",data_value[0]);

	bt_gatt_send_notification(&data);
}

void bt_gatt_char_notify_request_cb(tGattDescReadReq *char_notify)
{
	pr_info("enter");

}

void bt_gatt_desc_read_requset_cb(tGattDescReadReq *desc_read)
{
	pr_info("enter");
	char value[1];
	static unsigned char count = 0;

	pr_info("trans_id:%d,attr_handle:%d,offset:%d",desc_read->trans_id,
		desc_read->attr_handle,desc_read->offset);

	if(desc_read) {
		tGattSendReadRsp data;
		data.trans_id = desc_read->trans_id;
		data.svc_handle = desc_read->attr_handle;
		data.status = 0x0b;
		data.auth_req = 0x00;
		value[0]= count;
		data.value = value;
		data.value_len = 1;
		bt_gatt_send_read_response(&data);
		count ++;
	}
}

void bt_gatt_desc_write_request_cb(tGattDescWriteReq *desc_write)
{
	pr_info("enter");
}

tGattServerCb bt_gatt_callback = {
	.GattAddSvcCb = bt_gatt_add_service_cb,
	.GattAddCharCb = bt_gatt_add_char_cb,
	.GattAddDescCb = bt_gatt_add_desc_cb,
	.GattConnectionEventcb = bt_gatt_connection_cb,
	.GattCharReadReqCb = bt_gatt_char_read_request_cb,
	.GattCharWriteReqCb = bt_gatt_char_write_request_cb,
	.GattCharNotifyReqCb = bt_gatt_char_notify_request_cb,
	.GattDescReadReqCb = bt_gatt_desc_read_requset_cb,
	.GattDescWriteReqCb = bt_gatt_desc_write_request_cb,
	.GattSendIndicationCb = bt_gatt_send_indication_cb,
};

static void cmd_init(const char *arg)
{

	bt_gatt_server_init(&bt_gatt_callback);
	pr_info("Init");
}

static void cmd_deinit(const char *arg)
{
	pr_info("DeInit");
	bt_gatt_server_deinit();
}


static void cmd_add_service(const char *arg)
{
	tGattAddSvc svc;

	svc.number = 8;
	svc.uuid = TEST_SERVICE_UUID;
	svc.primary = true;

	bt_gatt_create_server(&svc);
}

static void cmd_add_char(const char *arg)
{
	tGattAddChar chr1;
	chr1.permissions = BT_GATT_PERM_READ | BT_GATT_PERM_WRITE;
	chr1.properties = BT_GATT_CHAR_PROPERTY_READ | BT_GATT_CHAR_PROPERTY_WRITE;
	chr1.svc_handle = service_handle;
	chr1.uuid = TEST_CHAR_UUID1;

	pr_info("add char");
	bt_gatt_add_characteristic(&chr1);

	tGattAddChar chr2;
	chr2.permissions = BT_GATT_PERM_READ | BT_GATT_PERM_WRITE;
	chr2.properties = BT_GATT_CHAR_PROPERTY_READ | BT_GATT_CHAR_PROPERTY_WRITE |
		BT_GATT_CHAR_PROPERTY_NOTIFY;
	chr2.svc_handle = service_handle;
	chr2.uuid = TEST_CHAR_UUID2;

	bt_gatt_add_characteristic(&chr2);

}

static void cmd_add_desc(const char *arg)
{
	tGattAddDesc desc;
	desc.permissions = BT_GATT_PERM_READ | BT_GATT_PERM_WRITE;
	desc.uuid = TEST_DESC_UUID;
	desc.svc_handle = service_handle;

	bt_gatt_add_descriptor(&desc);
}

static void cmd_start_service(const char *arg)
{
	tGattStarSvc start_svc;
	start_svc.svc_handle = service_handle;

	bt_gatt_start_service(&start_svc);
}

static void cmd_stop_service(const char *arg)
{
	tGattStopSvc stop_svc;
	stop_svc.svc_handle = service_handle;

	bt_gatt_stop_service(&stop_svc);
}

static void cmd_test(const char *arg)
{
	cmd_init(NULL);
	cmd_add_service(NULL);
	cmd_add_char(NULL);
	cmd_add_desc(NULL);
	cmd_start_service(NULL);
	enableAdv(true);
//	setAdvData();
	setAdvData(0x50,"AwBleTest1111",NULL);
}
/*INT32 CSM_sendResponse(INT32 conn_id,INT32 trans_id,INT32 status,
						INT32 handle, CHAR * p_value,INT32 value_len,
						INT32 auth_req) */
/*
 * TODO: status: rsp code?
 *	   : auth_req: error rsp error code?
 *	   Don't use this command.
 */
static void cmd_rsp(const char *arg)
{

	tGattSendReadRsp data;
	data.trans_id = 0;
	data.svc_handle =  char_handle;
	data.status = 0x0b;
	data.auth_req = 0x00;
	data.value = "ab";
	data.value_len = 2;
	bt_gatt_send_read_response(&data);
}

/*
 * INT32 CSM_sendIndication(INT32 server_if, INT32 handle,
 * INT32 conn_id, INT32 fg_confirm, CHAR * p_value, INT32 value_len)
 */
static void cmd_notify(const char *arg)
{
	tGattNotifyRsp data;
	data.attr_handle = 0x0005; // char value handle,get handle from add char callback.
	data.value = "abc";
	data.value_len = 3;

	bt_gatt_send_notification(&data);
}

static void cmd_indication(const char *arg)
{
	tGattIndicationRsp data;
	data.attr_handle = 0x0005; // char value handle,get handle from add char callback.
	data.value = "abc";
	data.value_len = 3;

	bt_gatt_send_indication(&data);
}

static void cmd_delet_server(const char *arg)
{
	tGattDelSvc DelObj;
	DelObj.svc_handle = service_handle;
	bt_gatt_delete_service(&DelObj);
}

static void cmd_quit(const char *arg)
{
	pr_info("Quit");
	cmd_stop_service(NULL);
	cmd_delet_server(NULL);
	enableAdv(false);
	__main_terminated = 1;
}

static void cmd_spawn(const char *arg)
{
	// spawn a second thread
//	spawn_thread();
}

static const struct {
	const char *cmd;
	const char *arg;
	void (*func) (const char *arg);
	const char *desc;
	char * (*gen) (const char *text, int state);
	void (*disp) (char **matches, int num_matches, int max_length);
} cmd_table[] = {
	{ "quit",         NULL,       cmd_quit, "Quit program" },
	{ "exit",         NULL,       cmd_quit },
	{ "test",         NULL,       cmd_test },
	{ "init",         NULL,       cmd_init },
	{ "as",			  NULL,       cmd_add_service },
	{ "ac",			  NULL,       cmd_add_char},
	{ "ad",			  NULL,       cmd_add_desc},
	{ "start",	  NULL,       cmd_start_service},
	{ "stop",	  NULL,       cmd_stop_service},
	{ "rsp",		  NULL,		  cmd_rsp},
	{ "notify",	  NULL,		  cmd_notify},
	{ "indication",	  NULL,		  cmd_indication},
	{ "desvc",	  NULL,       cmd_delet_server},
	{ "deinit",       NULL,       cmd_deinit },
	{ "spawn",       NULL,        cmd_spawn},
	{ "help" },
	{ }
};

static void process_cmdline(char *input_str, uint32_t len)
{
	char *cmd, *arg;
	int i;

	/* If user enter CTL + d, program will read an EOF and len
	 * is zero */
	if (!len) {
		pr_info("empty command\n");
		goto done;
	}

	if (!strlen(input_str))
		goto done;

	if (input_str[0] == '\n' || input_str[0] == '\r')
		goto done;

	if (input_str[len - 1] == '\n' || input_str[len - 1] == '\r')
		input_str[len - 1] = 0;

	/* rtb_printf("input_str: %s\n", input_str); */

	cmd = strtok_r(input_str, " ", &arg);
	if (!cmd)
		goto done;

	if (arg) {
		int len = strlen(arg);
		if (len > 0 && arg[len - 1] == ' ')
			arg[len - 1] = '\0';
	}
	/* rtb_printf("cmd %s -\n", cmd); */
	/* rtb_printf("arg %s -\n", arg); */

	for (i = 0; cmd_table[i].cmd; i++) {
		if (strcmp(cmd, cmd_table[i].cmd))
			continue;

		if (cmd_table[i].func) {
			cmd_table[i].func(arg);
			goto done;
		}
	}

	if (strcmp(cmd, "help")) {
		rtb_printf("Invalid command\n");
		goto done;
	}

	rtb_printf("Available commands:\n");

	for (i = 0; cmd_table[i].cmd; i++) {
		if (cmd_table[i].desc)
			rtb_printf("  %s %-*s %s\n", cmd_table[i].cmd,
					(int)(25 - strlen(cmd_table[i].cmd)),
					cmd_table[i].arg ? : "",
					cmd_table[i].desc ? : "");
	}
done:
	return;
}

static void stdin_read_handler(int fd)
{
	ssize_t read;
	size_t len = 0;
	char *line = NULL;

	read = getline(&line, &len, stdin);
	if (read < 0)
		return;

	if (read <= 1) {
		print_prompt();
		return;
	}

	line[read-1] = '\0';

	process_cmdline(line, strlen(line) + 1);
}

static int sigfd_setup(void)
{
	sigset_t mask;
	int fd;

	sigemptyset(&mask);
	sigaddset(&mask, SIGINT);
	sigaddset(&mask, SIGTERM);

	if (sigprocmask(SIG_BLOCK, &mask, NULL) < 0) {
		perror("Failed to set signal mask");
		return -1;
	}

	fd = signalfd(-1, &mask, 0);
	if (fd < 0) {
		perror("Failed to create signal descriptor");
		return -1;
	}

	return fd;
}


int main()
{
	int result;
	int sigfd;
	struct pollfd pfd[2];

	sigfd = sigfd_setup();
	if (sigfd < 0)
		return EXIT_FAILURE;

	pfd[0].fd = sigfd;
	pfd[0].events = POLLIN | POLLHUP | POLLERR;
	pfd[1].fd = fileno(stdin);
	pfd[1].events = POLLIN | POLLHUP | POLLERR;


	print_prompt();

	while (!__main_terminated) {
		pfd[0].revents = 0;
		pfd[1].revents = 0;
		if (poll(pfd, 2, -1) == -1) {
			if (errno == EINTR)
				continue;
			pr_error("Poll error: %s", strerror(errno));
			return EXIT_FAILURE;
		}

		if (pfd[0].revents & (POLLHUP | POLLERR)) {
			pr_error("Poll rdhup or hup or err");
			return EXIT_FAILURE;
		}

		if (pfd[1].revents & (POLLHUP | POLLERR)) {
			pr_error("Poll rdhup or hup or err");
			return EXIT_FAILURE;
		}

		if (pfd[0].revents & POLLIN) {
			struct signalfd_siginfo si;
			ssize_t ret;

			ret = read(pfd[0].fd, &si, sizeof(si));
			if (ret != sizeof(si))
				return EXIT_FAILURE;
			switch (si.ssi_signo) {
			case SIGINT:
			case SIGTERM:
				break;
			}
		}

		if (pfd[1].revents & POLLIN)
			stdin_read_handler(pfd[1].fd);
	}

	pr_info("exit");

	return 0;
}
