cmd_/home/dhleec/Project/R328/tina/out/r328s3-std/compile_dir/target/linux-r328s3-std/linux-4.9.118/user_headers/include/linux/tc_ematch/.install := bash scripts/headers_install.sh /home/dhleec/Project/R328/tina/out/r328s3-std/compile_dir/target/linux-r328s3-std/linux-4.9.118/user_headers/include/linux/tc_ematch ./include/uapi/linux/tc_ematch tc_em_cmp.h tc_em_meta.h tc_em_nbyte.h tc_em_text.h; bash scripts/headers_install.sh /home/dhleec/Project/R328/tina/out/r328s3-std/compile_dir/target/linux-r328s3-std/linux-4.9.118/user_headers/include/linux/tc_ematch ./include/linux/tc_ematch ; bash scripts/headers_install.sh /home/dhleec/Project/R328/tina/out/r328s3-std/compile_dir/target/linux-r328s3-std/linux-4.9.118/user_headers/include/linux/tc_ematch ./include/generated/uapi/linux/tc_ematch ; for F in ; do echo "$(pound)include <asm-generic/$$F>" > /home/dhleec/Project/R328/tina/out/r328s3-std/compile_dir/target/linux-r328s3-std/linux-4.9.118/user_headers/include/linux/tc_ematch/$$F; done; touch /home/dhleec/Project/R328/tina/out/r328s3-std/compile_dir/target/linux-r328s3-std/linux-4.9.118/user_headers/include/linux/tc_ematch/.install