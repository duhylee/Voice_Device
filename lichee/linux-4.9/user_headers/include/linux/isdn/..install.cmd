cmd_/home/dhleec/Project/R328/tina/out/r328s3-std/compile_dir/target/linux-r328s3-std/linux-4.9.118/user_headers/include/linux/isdn/.install := bash scripts/headers_install.sh /home/dhleec/Project/R328/tina/out/r328s3-std/compile_dir/target/linux-r328s3-std/linux-4.9.118/user_headers/include/linux/isdn ./include/uapi/linux/isdn capicmd.h; bash scripts/headers_install.sh /home/dhleec/Project/R328/tina/out/r328s3-std/compile_dir/target/linux-r328s3-std/linux-4.9.118/user_headers/include/linux/isdn ./include/linux/isdn ; bash scripts/headers_install.sh /home/dhleec/Project/R328/tina/out/r328s3-std/compile_dir/target/linux-r328s3-std/linux-4.9.118/user_headers/include/linux/isdn ./include/generated/uapi/linux/isdn ; for F in ; do echo "$(pound)include <asm-generic/$$F>" > /home/dhleec/Project/R328/tina/out/r328s3-std/compile_dir/target/linux-r328s3-std/linux-4.9.118/user_headers/include/linux/isdn/$$F; done; touch /home/dhleec/Project/R328/tina/out/r328s3-std/compile_dir/target/linux-r328s3-std/linux-4.9.118/user_headers/include/linux/isdn/.install