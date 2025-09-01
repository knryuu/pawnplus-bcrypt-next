# [PawnPlus](https://github.com/IS4Code/PawnPlus) Bcrypt NEXT
PawnPlus bcrypt NEXT with some improvement based on [samp_bcrypt plugin](https://github.com/Sreyas-Sreelal/samp-bcrypt).

Unlike the other versions, this one keeps everything simple and neat. Only 138 lines of code to implement it.

> [!WARNING]
> Only works with open.mp version, feel free to contribute if you want this to available for SA:MP.

## Installation
* Download [PawnPlus](https://github.com/IS4Code/PawnPlus/releases/latest) and [samp_bcrypt](https://github.com/Sreyas-Sreelal/samp-bcrypt/releases/latest), extract it to your server folder.
* Download pp-bcrypt.inc from the release page, put the .inc file to `pawno/include` or `qawno/include`.
* Use the include by typing `#include <pp-bcrypt>`.

## Functions
```pawn
native Task:bcrypt_async_hash(const input[], cost = BCRYPT_COST);
native Task:bcrypt_async_hash_s(ConstStringTag:input, cost = BCRYPT_COST);

native Task:bcrypt_async_verify(const input[], const hash[]);
native Task:bcrypt_async_verify_s(ConstStringTag:input, ConstStringTag:hash);

// Internal
native bcrypt_get_hash__(AmxString:hash, size = BCRYPT_HASH_LENGTH);
```

## Examples 
Refer to [test.pwn](/test.pwn) to see the usage of this include.
