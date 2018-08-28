/**

* @file       ECIES.h

* @brief      AES.

* @details	AES

* @author     peersafe

* @date       2017/12/09

* @version v1.0

* @par Copyright (c):

*      Copyright (c) 2016-2018 Peersafe Technology Co., Ltd.

* @par History:

*   v1.0: dbliu, 2017/12/09, originator\n

*/
//------------------------------------------------------------------------------
/*
 This file is part of chainsqld: https://github.com/chainsql/chainsqld
 Copyright (c) 2016-2018 Peersafe Technology Co., Ltd.
 
	chainsqld is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
 
	chainsqld is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	You should have received a copy of the GNU General Public License
	along with cpp-ethereum.  If not, see <http://www.gnu.org/licenses/>.
 */
//==============================================================================

#ifndef RIPPLE_CRYPTO_ECIES_H_INCLUDED
#define RIPPLE_CRYPTO_ECIES_H_INCLUDED

#include <ripple/basics/base_uint.h>
#include <ripple/basics/Blob.h>

namespace ripple {

// ECIES functions. These throw on failure

// encrypt/decrypt functions with integrity checking.
// Note that the other side must somehow know what keys to use

/** AES
*     encrypt functions with integrity checking
*     @param secretKey 
*     @param publicKey 
*     @param plaintext 
*     @return    
*     @note    ECIES functions. These throw on failure
*/
Blob encryptECIES (uint256 const& secretKey, Blob const& publicKey, Blob const& plaintext);

/** AES
*     decrypt functions with integrity checking
*     @param secretKey 
*     @param publicKey 
*     @param ciphertext 
*     @return    
*     @note    ECIES functions. These throw on failure
*/
Blob decryptECIES (uint256 const& secretKey, Blob const& publicKey, Blob const& ciphertext);

} // ripple

#endif
