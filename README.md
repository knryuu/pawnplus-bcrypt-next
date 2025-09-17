# [PawnPlus](https://github.com/IS4Code/PawnPlus) Bcrypt NEXT
PawnPlus bcrypt NEXT with some improvement based on [samp_bcrypt plugin](https://github.com/Sreyas-Sreelal/samp-bcrypt) only.

Unlike the other versions, this one keeps everything simple and neat. Only less than 200 lines of code to implement it.

> [!INFO]
> Now the include supports both open.mp and SA:MP seamlessly.

## Installation

### sampctl
Type the following command:
```bash
sampctl install knryuu/pawnplus-bcrypt-next
```
To install the include.

Began using the include by typing `#include <pp-bcrypt>`.

### Manual Installation
* Download [PawnPlus](https://github.com/IS4Code/PawnPlus/releases/latest) and [samp_bcrypt](https://github.com/Sreyas-Sreelal/samp-bcrypt/releases/latest), extract it to your server folder.
* Download pp-bcrypt.inc from the release page, put the .inc file to `pawno/include` or `qawno/include`.
* Began using the include by typing `#include <pp-bcrypt>`.

## Functions
```pawn
native Task:bcrypt_async_hash(const input[], cost = BCRYPT_COST);
native Task:bcrypt_async_hash_s(ConstStringTag:input, cost = BCRYPT_COST);

native Task:bcrypt_async_verify(const input[], const hash[]);
native Task:bcrypt_async_verify_s(ConstStringTag:input, ConstStringTag:hash);

native String:bcrypt_get_hash_s();
```

## Examples 
Refer to [test.pwn](/test.pwn) to see the usage of this include.
