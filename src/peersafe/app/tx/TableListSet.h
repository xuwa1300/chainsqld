/**

* @file       TableListSet.h

* @brief      chainSQL 交易类 TableListSet.

* @details	处理 chainSQL 交易类，其具体类型为 TableListSet

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

#ifndef RIPPLE_TX_TABLELISTSET_H_INCLUDED
#define RIPPLE_TX_TABLELISTSET_H_INCLUDED

#include <ripple/app/paths/RippleCalc.h>
#include <ripple/app/tx/impl/Transactor.h>
#include <ripple/basics/Log.h>
#include <ripple/protocol/TxFlags.h>
#include <peersafe/app/tx/ChainSqlTx.h>

namespace ripple {

/**

* chainSQL 交易类 TableListSet

* 处理 chainSQL 交易类，其具体类型为 TableListSet

*/
class TableListSet
    : public ChainSqlTx
{
public:
    TableListSet(ApplyContext& ctx)
        : ChainSqlTx(ctx)
    {
    }

    static
    TER
    preflightHandler(const STTx & tx, Application& app);
    static
    TER
    preflight (PreflightContext const& ctx);

    static
    TER
    preclaimHandler(ReadView const& view, const STTx & tx, Application& app);
    static
    TER
    preclaim(PreclaimContext const& ctx);

	static
    TER
    applyHandler(ApplyView& view, const STTx & tx, Application& app);
    TER doApply () override;

    static
    STObject generateTableEntry(const STTx &tx, ApplyView& view);

    static
    void UpdateTableSle(STEntry *pEntry, LedgerIndex createLgrSeq, uint256 createdLedgerHash, uint256 createdTxnHash,LedgerIndex previousTxnLgrSeq = 0,uint256 previousTxnLgrHash = uint256());

	std::pair<TER, std::string> dispose(TxStore& txStore, const STTx& tx);
};

} // ripple

#endif
