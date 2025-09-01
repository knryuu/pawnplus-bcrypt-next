
#include <open.mp>
#include <PawnPlus>
#include <samp_bcrypt>

#include "pp-bcrypt.inc"

main()
{
    new String:hashStr = await_str_s bcrypt_async_hash_s(@("test"));
    print_s(hashStr);

    new result_1 = await bcrypt_async_verify_s(@("test"), hashStr);

    if (result_1)
    {
        print("Complete 1/2!");
    }
    else
    {
        print("Fail! 1/2");
    }

    new hash[BCRYPT_HASH_LENGTH];
    await_str(hash) bcrypt_async_hash("test");
    print(hash);
	
    new result_2 = await bcrypt_async_verify("test", hash);

    if (result_2)
    {
        print("Complete 2/2!");
    }
    else
    {
        print("Fail! 2/2");
    }
	return 1;
}
