cmd_/home/dhleec/Project/R328/tina/out/r328s3-std/compile_dir/target/linux-r328s3-std/linux-4.9.118/user_headers/include/linux/sunrpc/.install := bash scripts/headers_install.sh /home/dhleec/Project/R328/tina/out/r328s3-std/compile_dir/target/linux-r328s3-std/linux-4.9.118/user_headers/include/linux/sunrpc ./include/uapi/linux/sunrpc debug.h; bash scripts/headers_install.sh /home/dhleec/Project/R328/tina/out/r328s3-std/compile_dir/target/linux-r328s3-std/linux-4.9.118/user_headers/include/linux/sunrpc ./include/linux/sunrpc ; bash scripts/headers_install.sh /home/dhleec/Project/R328/tina/out/r328s3-std/compile_dir/target/linux-r328s3-std/linux-4.9.118/user_headers/include/linux/sunrpc ./include/generated/uapi/linux/sunrpc ; for F in ; do echo "$(pound)include <asm-generic/$$F>" > /home/dhleec/Project/R328/tina/out/r328s3-std/compile_dir/target/linux-r328s3-std/linux-4.9.118/user_headers/include/linux/sunrpc/$$F; done; touch /home/dhleec/Project/R328/tina/out/r328s3-std/compile_dir/target/linux-r328s3-std/linux-4.9.118/user_headers/include/linux/sunrpc/.install