/*

	PawnPlus Bcrypt NEXT
	Versiao: 1.0

	PawnPlus Bcrypt is an extension include that adds Dynamic String with
	Task Await for samp_bcrypt.inc made by SyS.

	Copyright (C) 2025  Kanaru Yuuki

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU Affero General Public License as published
	by the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#if defined _inc_pawnplus_bcrypt
  #undef _inc_pawnplus_bcrypt
#endif

#if defined _samp_pp_bcrypt_included
	#endinput
#endif

#if !defined _PawnPlus_included
	#error "Include PawnPlus.inc first!"
#endif

#if !defined _samp_bcrypt_included
	#error "Include samp_bcrypt.inc first!"
#endif

#define _samp_pp_bcrypt_included

// Redirect Natives
native bcrypt_get_hash__(AmxString:hash, size = BCRYPT_HASH_LENGTH) = bcrypt_get_hash;

// Functions
stock Task:bcrypt_async_hash(const input[], cost = BCRYPT_COST)
{
	new
		Task:hash_task = task_new(),
		Handle:hash_handle = handle_new(hash_task, .weak = true);

	new callback_name[3];
	callback_name = amx_encode_value_public_name("_pp@__OnBcryptCalled", hash_handle);

	new result = pawn_call_native("bcrypt_hash", "dssds*", 0, callback_name, input, cost, "d", _:hash_handle);

	if (result)
	{
		handle_acquire(hash_handle);
	}
	else
	{
		task_set_error_ms(hash_task, amx_err_assert, 0);
	}
	return hash_task;
}

stock Task:bcrypt_async_hash_s(ConstStringTag:input, cost = BCRYPT_COST)
{
	new
		Task:hash_task = task_new(),
		Handle:hash_handle = handle_new(hash_task, .weak = true);

	new callback_name[3];
	callback_name = amx_encode_value_public_name("_pp@__OnBcryptCalled", hash_handle);

	new result = pawn_call_native("bcrypt_hash", "dsSds*", 1, callback_name, String:input, cost, "d", _:hash_handle);

	if (result)
	{
		handle_acquire(hash_handle);
	}
	else
	{
		task_set_error_ms(hash_task, amx_err_assert, 0);
	}
	return hash_task;
}

stock Task:bcrypt_async_verify(const input[], const hash[])
{
	new
		Task:hash_task = task_new(),
		Handle:hash_handle = handle_new(hash_task, .weak = true);

	new callback_name[3];
	callback_name = amx_encode_value_public_name("_pp@__OnBcryptCalled", hash_handle);

	new result = pawn_call_native("bcrypt_verify", "dssss*", 2, callback_name, String:input, String:hash, "d", _:hash_handle);

	if (result)
	{
		handle_acquire(hash_handle);
	}
	else
	{
		task_set_error_ms(hash_task, amx_err_assert, 0);
	}
	return hash_task;
}

stock Task:bcrypt_async_verify_s(ConstStringTag:input, ConstStringTag:hash)
{
	new
		Task:hash_task = task_new(),
		Handle:hash_handle = handle_new(hash_task, .weak = true);

	new callback_name[3];
	callback_name = amx_encode_value_public_name("_pp@__OnBcryptCalled", hash_handle);

	new result = pawn_call_native("bcrypt_verify", "dsSSs*", 2, callback_name, String:input, String:hash, "d", _:hash_handle);

	if (result)
	{
		handle_acquire(hash_handle);
	}
	else
	{
		task_set_error_ms(hash_task, amx_err_assert, 0);
	}
	return hash_task;
}

// Callbacks
forward _pp@__OnBcryptCalled(type__, state__, Handle:h__);
public _pp@__OnBcryptCalled(type__, state__, Handle:h__)
{
	if (type__ < 2)
	{
		if (!handle_linked(Handle:state__)) return 0;
		
		new Task:t = Task:handle_get(Handle:state__);

		if (type__ == 1)
		{
			new String:hash = str_new_buf(BCRYPT_HASH_LENGTH);
			bcrypt_get_hash__(hash);
			task_set_result_str_s(t, hash);
		}
		else
		{
			new hash[BCRYPT_HASH_LENGTH];
			bcrypt_get_hash(hash);
			task_set_result_str(t, hash);
		}
	}
	else
	{
		if (!handle_linked(h__)) return 0;
		
		new Task:t = Task:handle_get(h__);
		task_set_result(t, state__);
	}
	return 1;
}
