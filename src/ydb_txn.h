// This file defines the public interface to the ydb library

#if !defined(TOKU_YDB_TXN_H)
#define TOKU_YDB_TXN_H

#if defined(__cplusplus)
extern "C" {
#endif

int locked_txn_begin(DB_ENV *env, DB_TXN * stxn, DB_TXN ** txn, u_int32_t flags);
int toku_txn_begin(DB_ENV *env, DB_TXN * stxn, DB_TXN ** txn, u_int32_t flags, bool internal, bool holds_ydb_lock);
int toku_txn_commit(DB_TXN * txn, u_int32_t flags, TXN_PROGRESS_POLL_FUNCTION, void*, bool release_multi_operation_client_lock);
int toku_txn_abort(DB_TXN * txn, TXN_PROGRESS_POLL_FUNCTION, void*, bool release_multi_operation_client_lock);
int locked_txn_commit(DB_TXN *txn, u_int32_t flags);
int locked_txn_abort(DB_TXN *txn);

#if defined(__cplusplus)
}
#endif

#endif