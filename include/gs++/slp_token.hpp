#ifndef GS_SLP_TOKEN_HPP
#define GS_SLP_TOKEN_HPP

#include <cassert>
#include <variant>

#include <absl/container/flat_hash_map.h>
#include <absl/container/node_hash_map.h>

#include <gs++/bhash.hpp>
#include <gs++/slp_transaction.hpp>


namespace gs {

struct slp_token
{
    gs::tokenid tokenid;
    gs::transaction& genesis;

    absl::flat_hash_map<gs::txid, gs::transaction> transactions;
    absl::flat_hash_set<gs::outpoint> utxos;


    slp_token(const gs::transaction& tx)
    : tokenid(tx.txid)
    , transactions({{ tx.txid, tx }})
    , genesis(transactions.at(tx.txid))
    {
        assert(tx.type == gs::slp_transaction_type::genesis);
    }
};

}

#endif