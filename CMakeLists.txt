cmake_minimum_required(VERSION 3.10)
project(insecure-format-strings)

# -----------------------------------------------------------------
#
# FORMAT: Hacking, the Art of Exploitation (Jon Erickson)
#
# -----------------------------------------------------------------

add_executable(getenvaddr src/getenvaddr.c)

add_executable(format_exploitable src/exploitable.c)
target_compile_options(format_exploitable PRIVATE -Wno-format-security)
