# Task 3: Data Structure Investigation
The objective of this task is to document all internal data structures defined in io_uring. 

| Structure name | Defined in | Attributes | Caller Functions Source | Source Caller | Usage |
|---|---|---|---|---|---|
| io_fadvise | advise.c | advice, file, len, offset | io_madvise | advise.c | used in body |
| io_fadvise | advise.c | advice, file, len, offset | io_madvise | advise.h | used in body |
| io_fadvise | advise.c | advice, file, len, offset | io_fadvise_force_async | advise.c | declared in param |
| io_fadvise | advise.c | advice, file, len, offset | io_fadvise_prep | advise.c | used in body |
| io_fadvise | advise.c | advice, file, len, offset | io_fadvise_prep | advise.h | used in body |
| io_fadvise | advise.c | advice, file, len, offset | io_fadvise | advise.c | used in body |
| io_fadvise | advise.c | advice, file, len, offset | io_fadvise | advise.h | used in body |
| io_fadvise | advise.c | advice, file, len, offset | io_eopnotsupp_prep | opdef.c | used in body |
| io_madvise | advise.c | addr, advice, file, len | io_madvise_prep | advise.c | used in body |
| io_madvise | advise.c | addr, advice, file, len | io_madvise_prep | advise.h | used in body |
| io_madvise | advise.c | addr, advice, file, len | io_madvise | advise.c | used in body |
| io_madvise | advise.c | addr, advice, file, len | io_madvise | advise.h | used in body |
| io_madvise | advise.c | addr, advice, file, len | io_eopnotsupp_prep | opdef.c | used in body |
| io_cancel | cancel.c | addr, fd, file, flags, opcode | io_async_cancel_prep | cancel.c | used in body |
| io_cancel | cancel.c | addr, fd, file, flags, opcode | io_async_cancel_prep | cancel.h | used in body |
| io_cancel | cancel.c | addr, fd, file, flags, opcode | io_async_cancel | cancel.c | used in body |
| io_cancel | cancel.c | addr, fd, file, flags, opcode | io_async_cancel | cancel.h | used in body |
| io_cancel_data | cancel.h | ctx, data, file, union | io_cancel_req_match | cancel.c | declared in param |
| io_cancel_data | cancel.h | ctx, data, file, union | io_cancel_req_match | cancel.h | declared in param |
| io_cancel_data | cancel.h | ctx, data, file, union | io_cancel_req_match | poll.c | declared in param |
| io_cancel_data | cancel.h | ctx, data, file, union | io_cancel_req_match | timeout.c | declared in param |
| io_cancel_data | cancel.h | ctx, data, file, union | io_cancel_cb | cancel.c | used in body |
| io_cancel_data | cancel.h | ctx, data, file, union | io_async_cancel_one | cancel.c | declared in param, used in body |
| io_cancel_data | cancel.h | ctx, data, file, union | io_try_cancel | cancel.c | declared in param |
| io_cancel_data | cancel.h | ctx, data, file, union | io_try_cancel | cancel.h | declared in param |
| io_cancel_data | cancel.h | ctx, data, file, union | io_try_cancel | timeout.c | declared in param |
| io_cancel_data | cancel.h | ctx, data, file, union | io_async_cancel_prep | cancel.c | used in body |
| io_cancel_data | cancel.h | ctx, data, file, union | io_async_cancel_prep | cancel.h | used in body |
| io_cancel_data | cancel.h | ctx, data, file, union | __io_async_cancel | cancel.c | declared in param |
| io_cancel_data | cancel.h | ctx, data, file, union | io_async_cancel | cancel.c | used in body |
| io_cancel_data | cancel.h | ctx, data, file, union | io_async_cancel | cancel.h | used in body |
| io_cancel_data | cancel.h | ctx, data, file, union | __io_sync_cancel | cancel.c | declared in param, used in body |
| io_cancel_data | cancel.h | ctx, data, file, union | __io_futex_cancel | futex.c | used in body |
| io_cancel_data | cancel.h | ctx, data, file, union | io_futex_cancel | cancel.c | declared in param |
| io_cancel_data | cancel.h | ctx, data, file, union | io_futex_cancel | futex.c | declared in param |
| io_cancel_data | cancel.h | ctx, data, file, union | io_futex_cancel | futex.h | declared in param |
| io_cancel_data | cancel.h | ctx, data, file, union | io_futex_cancel | cancel.c | declared in param |
| io_cancel_data | cancel.h | ctx, data, file, union | io_futex_cancel | futex.c | declared in param |
| io_cancel_data | cancel.h | ctx, data, file, union | io_futex_cancel | futex.h | declared in param |
| io_cancel_data | cancel.h | ctx, data, file, union | io_poll_remove_all | io_uring.c | used in body |
| io_cancel_data | cancel.h | ctx, data, file, union | io_poll_remove_all | poll.c | used in body |
| io_cancel_data | cancel.h | ctx, data, file, union | io_poll_remove_all | poll.h | used in body |
| io_cancel_data | cancel.h | ctx, data, file, union | io_poll_find | poll.c | declared in param, used in body |
| io_cancel_data | cancel.h | ctx, data, file, union | io_poll_file_find | poll.c | declared in param |
| io_cancel_data | cancel.h | ctx, data, file, union | io_poll_disarm | poll.c | used in body |
| io_cancel_data | cancel.h | ctx, data, file, union | __io_poll_cancel | poll.c | declared in param, used in body |
| io_cancel_data | cancel.h | ctx, data, file, union | io_poll_cancel | cancel.c | declared in param |
| io_cancel_data | cancel.h | ctx, data, file, union | io_poll_cancel | poll.c | declared in param |
| io_cancel_data | cancel.h | ctx, data, file, union | io_poll_cancel | poll.h | declared in param |
| io_cancel_data | cancel.h | ctx, data, file, union | io_poll_remove | poll.c | used in body |
| io_cancel_data | cancel.h | ctx, data, file, union | io_poll_remove | poll.h | used in body |
| io_cancel_data | cancel.h | ctx, data, file, union | io_poll_multishot_retry | poll.h | used in body |
| io_cancel_data | cancel.h | ctx, data, file, union | io_poll_multishot_retry | rw.c | used in body |
| io_cancel_data | cancel.h | ctx, data, file, union | io_timeout_fn | timeout.c | used in body |
| io_cancel_data | cancel.h | ctx, data, file, union | io_req_task_link_timeout | timeout.c | used in body |
| io_cancel_data | cancel.h | ctx, data, file, union | io_timeout_get_clock | timeout.c | used in body |
| io_cancel_data | cancel.h | ctx, data, file, union | io_timeout_remove | timeout.c | used in body |
| io_cancel_data | cancel.h | ctx, data, file, union | io_timeout_remove | timeout.h | used in body |
| io_cancel_data | cancel.h | ctx, data, file, union | io_disarm_linked_timeout | timeout.c | used in body |
| io_cancel_data | cancel.h | ctx, data, file, union | io_disarm_linked_timeout | timeout.h | used in body |
| io_cancel_data | cancel.h | ctx, data, file, union | __io_waitid_cancel | waitid.c | used in body |
| io_cancel_data | cancel.h | ctx, data, file, union | io_waitid_cancel | cancel.c | declared in param |
| io_cancel_data | cancel.h | ctx, data, file, union | io_waitid_cancel | waitid.c | declared in param |
| io_cancel_data | cancel.h | ctx, data, file, union | io_waitid_cancel | waitid.h | declared in param |
| io_epoll | epoll.c | epfd, event, fd, file, op | io_epoll_ctl_prep | epoll.c | used in body |
| io_epoll | epoll.c | epfd, event, fd, file, op | io_epoll_ctl_prep | epoll.h | used in body |
| io_epoll | epoll.c | epfd, event, fd, file, op | io_epoll_ctl | epoll.c | used in body |
| io_epoll | epoll.c | epfd, event, fd, file, op | io_epoll_ctl | epoll.h | used in body |
| io_epoll_wait | epoll.c | events, file, maxevents | io_epoll_wait_prep | epoll.c | used in body |
| io_epoll_wait | epoll.c | events, file, maxevents | io_epoll_wait_prep | epoll.h | used in body |
| io_epoll_wait | epoll.c | events, file, maxevents | io_epoll_wait | epoll.c | used in body |
| io_epoll_wait | epoll.c | events, file, maxevents | io_epoll_wait | epoll.h | used in body |
| io_epoll_wait | epoll.c | events, file, maxevents | io_eopnotsupp_prep | opdef.c | used in body |
| io_ev_fd | eventfd.c | completion_lock, cq_ev_fd, eventfd_async, last_cq_tail, ops, rcu, refs | io_eventfd_free | eventfd.c | used in body |
| io_ev_fd | eventfd.c | completion_lock, cq_ev_fd, eventfd_async, last_cq_tail, ops, rcu, refs | io_eventfd_put | eventfd.c | declared in param |
| io_ev_fd | eventfd.c | completion_lock, cq_ev_fd, eventfd_async, last_cq_tail, ops, rcu, refs | io_eventfd_do_signal | eventfd.c | used in body |
| io_ev_fd | eventfd.c | completion_lock, cq_ev_fd, eventfd_async, last_cq_tail, ops, rcu, refs | io_eventfd_release | eventfd.c | declared in param, used in body |
| io_ev_fd | eventfd.c | completion_lock, cq_ev_fd, eventfd_async, last_cq_tail, ops, rcu, refs | __io_eventfd_signal | eventfd.c | declared in param, used in body |
| io_ev_fd | eventfd.c | completion_lock, cq_ev_fd, eventfd_async, last_cq_tail, ops, rcu, refs | io_eventfd_trigger | eventfd.c | declared in param, used in body |
| io_ev_fd | eventfd.c | completion_lock, cq_ev_fd, eventfd_async, last_cq_tail, ops, rcu, refs | io_eventfd_grab | eventfd.c | used in body |
| io_ev_fd | eventfd.c | completion_lock, cq_ev_fd, eventfd_async, last_cq_tail, ops, rcu, refs | io_eventfd_signal | eventfd.c | used in body |
| io_ev_fd | eventfd.c | completion_lock, cq_ev_fd, eventfd_async, last_cq_tail, ops, rcu, refs | io_eventfd_signal | eventfd.h | used in body |
| io_ev_fd | eventfd.c | completion_lock, cq_ev_fd, eventfd_async, last_cq_tail, ops, rcu, refs | io_eventfd_signal | io_uring.c | used in body |
| io_ev_fd | eventfd.c | completion_lock, cq_ev_fd, eventfd_async, last_cq_tail, ops, rcu, refs | io_eventfd_flush_signal | eventfd.c | used in body |
| io_ev_fd | eventfd.c | completion_lock, cq_ev_fd, eventfd_async, last_cq_tail, ops, rcu, refs | io_eventfd_flush_signal | eventfd.h | used in body |
| io_ev_fd | eventfd.c | completion_lock, cq_ev_fd, eventfd_async, last_cq_tail, ops, rcu, refs | io_eventfd_flush_signal | io_uring.c | used in body |
| io_ev_fd | eventfd.c | completion_lock, cq_ev_fd, eventfd_async, last_cq_tail, ops, rcu, refs | io_eventfd_register | eventfd.c | used in body |
| io_ev_fd | eventfd.c | completion_lock, cq_ev_fd, eventfd_async, last_cq_tail, ops, rcu, refs | io_eventfd_register | eventfd.h | used in body |
| io_ev_fd | eventfd.c | completion_lock, cq_ev_fd, eventfd_async, last_cq_tail, ops, rcu, refs | io_eventfd_register | register.c | used in body |
| io_ev_fd | eventfd.c | completion_lock, cq_ev_fd, eventfd_async, last_cq_tail, ops, rcu, refs | io_eventfd_unregister | eventfd.c | used in body |
| io_ev_fd | eventfd.c | completion_lock, cq_ev_fd, eventfd_async, last_cq_tail, ops, rcu, refs | io_eventfd_unregister | eventfd.h | used in body |
| io_ev_fd | eventfd.c | completion_lock, cq_ev_fd, eventfd_async, last_cq_tail, ops, rcu, refs | io_eventfd_unregister | io_uring.c | used in body |
| io_ev_fd | eventfd.c | completion_lock, cq_ev_fd, eventfd_async, last_cq_tail, ops, rcu, refs | io_eventfd_unregister | register.c | used in body |
| io_ev_fd | eventfd.c | completion_lock, cq_ev_fd, eventfd_async, last_cq_tail, ops, rcu, refs | io_eventfd_unregister | register.h | used in body |
| io_rename | fs.c | file, flags, new_dfd, newpath, old_dfd, oldpath | io_renameat_prep | fs.c | used in body |
| io_rename | fs.c | file, flags, new_dfd, newpath, old_dfd, oldpath | io_renameat_prep | fs.h | used in body |
| io_rename | fs.c | file, flags, new_dfd, newpath, old_dfd, oldpath | io_renameat | fs.c | used in body |
| io_rename | fs.c | file, flags, new_dfd, newpath, old_dfd, oldpath | io_renameat | fs.h | used in body |
| io_rename | fs.c | file, flags, new_dfd, newpath, old_dfd, oldpath | io_renameat_cleanup | fs.c | used in body |
| io_rename | fs.c | file, flags, new_dfd, newpath, old_dfd, oldpath | io_renameat_cleanup | fs.h | used in body |
| io_unlink | fs.c | dfd, file, filename, flags | io_unlinkat_prep | fs.c | used in body |
| io_unlink | fs.c | dfd, file, filename, flags | io_unlinkat_prep | fs.h | used in body |
| io_unlink | fs.c | dfd, file, filename, flags | io_unlinkat | fs.c | used in body |
| io_unlink | fs.c | dfd, file, filename, flags | io_unlinkat | fs.h | used in body |
| io_unlink | fs.c | dfd, file, filename, flags | io_unlinkat_cleanup | fs.c | used in body |
| io_unlink | fs.c | dfd, file, filename, flags | io_unlinkat_cleanup | fs.h | used in body |
| io_mkdir | fs.c | dfd, file, filename, mode | io_mkdirat_prep | fs.c | used in body |
| io_mkdir | fs.c | dfd, file, filename, mode | io_mkdirat_prep | fs.h | used in body |
| io_mkdir | fs.c | dfd, file, filename, mode | io_mkdirat | fs.c | used in body |
| io_mkdir | fs.c | dfd, file, filename, mode | io_mkdirat | fs.h | used in body |
| io_mkdir | fs.c | dfd, file, filename, mode | io_mkdirat_cleanup | fs.c | used in body |
| io_mkdir | fs.c | dfd, file, filename, mode | io_mkdirat_cleanup | fs.h | used in body |
| io_link | fs.c | file, flags, new_dfd, newpath, old_dfd, oldpath | io_symlinkat_prep | fs.c | used in body |
| io_link | fs.c | file, flags, new_dfd, newpath, old_dfd, oldpath | io_symlinkat_prep | fs.h | used in body |
| io_link | fs.c | file, flags, new_dfd, newpath, old_dfd, oldpath | io_symlinkat | fs.c | used in body |
| io_link | fs.c | file, flags, new_dfd, newpath, old_dfd, oldpath | io_symlinkat | fs.h | used in body |
| io_link | fs.c | file, flags, new_dfd, newpath, old_dfd, oldpath | io_linkat_prep | fs.c | used in body |
| io_link | fs.c | file, flags, new_dfd, newpath, old_dfd, oldpath | io_linkat_prep | fs.h | used in body |
| io_link | fs.c | file, flags, new_dfd, newpath, old_dfd, oldpath | io_linkat | fs.c | used in body |
| io_link | fs.c | file, flags, new_dfd, newpath, old_dfd, oldpath | io_linkat | fs.h | used in body |
| io_link | fs.c | file, flags, new_dfd, newpath, old_dfd, oldpath | io_link_cleanup | fs.c | used in body |
| io_link | fs.c | file, flags, new_dfd, newpath, old_dfd, oldpath | io_link_cleanup | fs.h | used in body |
| io_futex | futex.c | file, uaddr, union, uwaitv | io_futexv_complete | futex.c | used in body |
| io_futex | futex.c | file, uaddr, union, uwaitv | io_futexv_claim | futex.c | declared in param |
| io_futex | futex.c | file, uaddr, union, uwaitv | __io_futex_cancel | futex.c | used in body |
| io_futex | futex.c | file, uaddr, union, uwaitv | io_futex_prep | futex.c | used in body |
| io_futex | futex.c | file, uaddr, union, uwaitv | io_futex_prep | futex.h | used in body |
| io_futex | futex.c | file, uaddr, union, uwaitv | io_futex_wakev_fn | futex.c | used in body |
| io_futex | futex.c | file, uaddr, union, uwaitv | io_futexv_prep | futex.c | used in body |
| io_futex | futex.c | file, uaddr, union, uwaitv | io_futexv_prep | futex.h | used in body |
| io_futex | futex.c | file, uaddr, union, uwaitv | io_futexv_wait | futex.c | used in body |
| io_futex | futex.c | file, uaddr, union, uwaitv | io_futexv_wait | futex.h | used in body |
| io_futex | futex.c | file, uaddr, union, uwaitv | io_futex_wait | futex.c | used in body |
| io_futex | futex.c | file, uaddr, union, uwaitv | io_futex_wait | futex.h | used in body |
| io_futex | futex.c | file, uaddr, union, uwaitv | io_futex_wake | futex.c | used in body |
| io_futex | futex.c | file, uaddr, union, uwaitv | io_futex_wake | futex.h | used in body |
| io_futex_data | futex.c | q, req | io_futex_cache_init | futex.c | used in body |
| io_futex_data | futex.c | q, req | io_futex_cache_init | futex.h | used in body |
| io_futex_data | futex.c | q, req | io_futex_cache_init | io_uring.c | used in body |
| io_futex_data | futex.c | q, req | __io_futex_cancel | futex.c | used in body |
| io_futex_data | futex.c | q, req | io_futex_wake_fn | futex.c | used in body |
| io_futex_data | futex.c | q, req | io_futex_wait | futex.c | used in body |
| io_futex_data | futex.c | q, req | io_futex_wait | futex.h | used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_worker_get | io-wq.c | declared in param, used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_worker_release | io-wq.c | declared in param |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_work_get_acct | io-wq.c | used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_wq_get_acct | io-wq.c | declared in param |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_wq_worker_stopped | io-wq.c | used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_wq_worker_stopped | io-wq.h | used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_wq_worker_stopped | io_uring.c | used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_worker_cancel_cb | io-wq.c | declared in param |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_task_worker_match | io-wq.c | used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_worker_exit | io-wq.c | declared in param |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | __io_acct_run_queue | io-wq.c | used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_wq_create_worker | io-wq.c | used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_wq_inc_running | io-wq.c | declared in param |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | create_worker_cb | io-wq.c | used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_queue_worker_create | io-wq.c | declared in param, used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_wq_dec_running | io-wq.c | declared in param, used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | __io_worker_busy | io-wq.c | declared in param, used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_wait_on_hash | io-wq.c | used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_assign_current_work | io-wq.c | declared in param, used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_wq_worker | io-wq.c | used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_wq_worker_running | io-wq.c | used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_wq_worker_running | io-wq.h | used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_wq_worker_sleeping | io-wq.c | used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_wq_worker_sleeping | io-wq.h | used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_init_new_worker | io-wq.c | declared in param |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_wq_work_match_all | io-wq.c | used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_should_retry_thread | io-wq.c | declared in param, used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | queue_create_worker_retry | io-wq.c | declared in param |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | create_worker_cont | io-wq.c | used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_workqueue_create | io-wq.c | used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | create_io_worker | io-wq.c | used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_wq_worker_wake | io-wq.c | declared in param |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_wq_hash_work | io-wq.c | used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_wq_hash_work | io-wq.h | used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_wq_hash_work | io_uring.c | used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | __io_wq_worker_cancel | io-wq.c | declared in param, used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_wq_worker_cancel | io-wq.c | declared in param |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_task_work_match | io-wq.c | used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_wq_cancel_tw_create | io-wq.c | used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_wq_put_and_exit | io-wq.c | used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_wq_put_and_exit | io-wq.h | used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_wq_put_and_exit | tctx.c | used in body |
| io_worker | io-wq.c | acct, all_list, create_state, create_work, cur_work, flags, init_retries, lock, nulls_node, rcu, ref, ref_done, task, union, work, wq | io_wq_worker_affinity | io-wq.c | declared in param |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_worker_release | io-wq.c | used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_get_acct | io-wq.c | used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_work_get_acct | io-wq.c | used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_worker_cancel_cb | io-wq.c | used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_worker_exit | io-wq.c | used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | __io_acct_run_queue | io-wq.c | declared in param, used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_wq_create_worker | io-wq.c | declared in param |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_wq_inc_running | io-wq.c | used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | create_worker_cb | io-wq.c | used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_queue_worker_create | io-wq.c | declared in param |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_wq_dec_running | io-wq.c | used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | __io_worker_busy | io-wq.c | declared in param, used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_wait_on_hash | io-wq.c | used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_assign_current_work | io-wq.c | used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_wq_worker | io-wq.c | used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_wq_worker_sleeping | io-wq.c | used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_wq_worker_sleeping | io-wq.h | used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_init_new_worker | io-wq.c | declared in param |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | create_worker_cont | io-wq.c | used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_workqueue_create | io-wq.c | used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | create_io_worker | io-wq.c | declared in param, used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_run_cancel | io-wq.c | used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_wq_insert_work | io-wq.c | declared in param |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_wq_enqueue | io-wq.c | used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_wq_enqueue | io-wq.h | used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_wq_enqueue | io_uring.c | used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_wq_worker_cancel | io-wq.c | used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_wq_remove_pending | io-wq.c | declared in param, used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_acct_cancel_pending_work | io-wq.c | declared in param |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_wq_cancel_pending_work | io-wq.c | used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_acct_cancel_running_work | io-wq.c | declared in param |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_wq_hash_wake | io-wq.c | used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_wq_create | io-wq.c | used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_wq_create | io-wq.h | used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_wq_create | tctx.c | used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_wq_max_workers | io-wq.c | used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_wq_max_workers | io-wq.h | used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_wq_max_workers | register.c | used in body |
| io_wq_acct | io-wq.c | all_list, flags, free_list, lists, lock, max_workers, nr_running, nr_workers, read, work_list, workers_lock | io_wq_max_workers | tctx.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_async_cancel_one | cancel.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_worker_release | io-wq.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_get_acct | io-wq.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_work_get_acct | io-wq.c | declared in param |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_get_acct | io-wq.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_worker_ref_put | io-wq.c | declared in param |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_worker_cancel_cb | io-wq.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_worker_exit | io-wq.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | __io_acct_run_queue | io-wq.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_create_worker | io-wq.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | create_worker_cb | io-wq.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_queue_worker_create | io-wq.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_dec_running | io-wq.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_get_work_hash | io-wq.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wait_on_hash | io-wq.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_assign_current_work | io-wq.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_worker | io-wq.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_worker_sleeping | io-wq.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_worker_sleeping | io-wq.h | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_init_new_worker | io-wq.c | declared in param |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | create_worker_cont | io-wq.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_workqueue_create | io-wq.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | create_io_worker | io-wq.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_worker_wake | io-wq.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_run_cancel | io-wq.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_insert_work | io-wq.c | declared in param |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_work_match_item | io-wq.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_enqueue | io-wq.c | declared in param |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_enqueue | io-wq.h | declared in param |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_enqueue | io_uring.c | declared in param |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_worker_cancel | io-wq.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_remove_pending | io-wq.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_acct_cancel_pending_work | io-wq.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_cancel_pending_work | io-wq.c | declared in param |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_acct_cancel_running_work | io-wq.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_cancel_running_work | io-wq.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_cancel_cb | cancel.c | declared in param |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_cancel_cb | io-wq.c | declared in param |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_cancel_cb | io-wq.h | declared in param |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_cancel_cb | io_uring.c | declared in param |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_hash_wake | io-wq.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_create | io-wq.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_create | io-wq.h | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_create | tctx.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_task_work_match | io-wq.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_exit_start | io-wq.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_exit_start | io-wq.h | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_exit_start | io_uring.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_cancel_tw_create | io-wq.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_exit_workers | io-wq.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_destroy | io-wq.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_put_and_exit | io-wq.c | declared in param |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_put_and_exit | io-wq.h | declared in param |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_put_and_exit | tctx.c | declared in param |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_worker_affinity | io-wq.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | __io_wq_cpu_online | io-wq.c | declared in param |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_cpu_online | io-wq.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_cpu_offline | io-wq.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_cpu_affinity | io-wq.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_cpu_affinity | io-wq.h | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_cpu_affinity | register.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_cpu_affinity | sqpoll.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_max_workers | io-wq.c | declared in param |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_max_workers | io-wq.h | declared in param |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_max_workers | register.c | declared in param |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_max_workers | tctx.c | declared in param |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_put_hash | io-wq.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_put_hash | io-wq.h | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_put_hash | io_uring.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_is_hashed | io-wq.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_is_hashed | io-wq.h | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_wq_is_hashed | io_uring.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_queue_iowq | io_uring.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_ring_exit_work | io_uring.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_ring_exit_work | sqpoll.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_uring_try_cancel_iowq | io_uring.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_uring_try_cancel_iowq | tctx.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_uring_try_cancel_requests | io_uring.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | advise.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | alloc_cache.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | alloc_cache.h | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | cancel.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | cancel.h | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | epoll.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | eventfd.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | fdinfo.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | filetable.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | fs.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | futex.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | io-wq.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | io-wq.h | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | io_uring.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | io_uring.h | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | kbuf.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | kbuf.h | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | memmap.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | msg_ring.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | napi.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | napi.h | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | net.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | nop.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | notif.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | notif.h | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | opdef.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | openclose.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | poll.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | refs.h | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | register.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | rsrc.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | rsrc.h | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | rw.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | slist.h | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | splice.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | sqpoll.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | statx.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | sync.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | tctx.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | tctx.h | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | timeout.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | timeout.h | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | truncate.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | uring_cmd.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | waitid.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | xattr.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | if | zcrx.c | declared in param, used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_uring_cancel_generic | io_uring.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_uring_cancel_generic | io_uring.h | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_uring_cancel_generic | sqpoll.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_unregister_iowq_aff | register.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | __io_uring_free | io_uring.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | __io_uring_free | tctx.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_uring_alloc_task_context | io_uring.h | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_uring_alloc_task_context | sqpoll.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_uring_alloc_task_context | tctx.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_uring_alloc_task_context | tctx.h | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | __io_uring_add_tctx_node | io_uring.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | __io_uring_add_tctx_node | tctx.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | __io_uring_add_tctx_node | tctx.h | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_uring_clean_tctx | io_uring.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_uring_clean_tctx | tctx.c | used in body |
| io_wq | io-wq.c | IO_WQ_ACCT_NR, IO_WQ_NR_HASH_BUCKETS, cpu_mask, cpuhp_node, do_work, free_work, hash, state, task, wait, worker_done, worker_refs | io_uring_clean_tctx | tctx.h | used in body |
| io_cb_cancel_data | io-wq.c | cancel_all, data, fn, nr_pending, nr_running | create_worker_cont | io-wq.c | used in body |
| io_cb_cancel_data | io-wq.c | cancel_all, data, fn, nr_pending, nr_running | io_wq_enqueue | io-wq.c | used in body |
| io_cb_cancel_data | io-wq.c | cancel_all, data, fn, nr_pending, nr_running | io_wq_enqueue | io-wq.h | used in body |
| io_cb_cancel_data | io-wq.c | cancel_all, data, fn, nr_pending, nr_running | io_wq_enqueue | io_uring.c | used in body |
| io_cb_cancel_data | io-wq.c | cancel_all, data, fn, nr_pending, nr_running | io_wq_hash_work | io-wq.c | used in body |
| io_cb_cancel_data | io-wq.c | cancel_all, data, fn, nr_pending, nr_running | io_wq_hash_work | io-wq.h | used in body |
| io_cb_cancel_data | io-wq.c | cancel_all, data, fn, nr_pending, nr_running | io_wq_hash_work | io_uring.c | used in body |
| io_cb_cancel_data | io-wq.c | cancel_all, data, fn, nr_pending, nr_running | __io_wq_worker_cancel | io-wq.c | declared in param |
| io_cb_cancel_data | io-wq.c | cancel_all, data, fn, nr_pending, nr_running | io_wq_worker_cancel | io-wq.c | used in body |
| io_cb_cancel_data | io-wq.c | cancel_all, data, fn, nr_pending, nr_running | io_wq_remove_pending | io-wq.c | used in body |
| io_cb_cancel_data | io-wq.c | cancel_all, data, fn, nr_pending, nr_running | io_acct_cancel_pending_work | io-wq.c | declared in param, used in body |
| io_cb_cancel_data | io-wq.c | cancel_all, data, fn, nr_pending, nr_running | io_wq_cancel_pending_work | io-wq.c | declared in param, used in body |
| io_cb_cancel_data | io-wq.c | cancel_all, data, fn, nr_pending, nr_running | io_acct_cancel_running_work | io-wq.c | declared in param, used in body |
| io_cb_cancel_data | io-wq.c | cancel_all, data, fn, nr_pending, nr_running | io_wq_cancel_running_work | io-wq.c | declared in param |
| io_cb_cancel_data | io-wq.c | cancel_all, data, fn, nr_pending, nr_running | io_wq_cancel_cb | cancel.c | used in body |
| io_cb_cancel_data | io-wq.c | cancel_all, data, fn, nr_pending, nr_running | io_wq_cancel_cb | io-wq.c | used in body |
| io_cb_cancel_data | io-wq.c | cancel_all, data, fn, nr_pending, nr_running | io_wq_cancel_cb | io-wq.h | used in body |
| io_cb_cancel_data | io-wq.c | cancel_all, data, fn, nr_pending, nr_running | io_wq_cancel_cb | io_uring.c | used in body |
| io_cb_cancel_data | io-wq.c | cancel_all, data, fn, nr_pending, nr_running | io_wq_destroy | io-wq.c | used in body |
| online_data | io-wq.c | cpu, online | io_wq_put_and_exit | io-wq.c | used in body |
| online_data | io-wq.c | cpu, online | io_wq_put_and_exit | io-wq.h | used in body |
| online_data | io-wq.c | cpu, online | io_wq_put_and_exit | tctx.c | used in body |
| online_data | io-wq.c | cpu, online | io_wq_worker_affinity | io-wq.c | used in body |
| online_data | io-wq.c | cpu, online | __io_wq_cpu_online | io-wq.c | used in body |
| io_wq_hash | io-wq.h | map, refs, wait | io_wq_put_hash | io-wq.c | declared in param, used in body |
| io_wq_hash | io-wq.h | map, refs, wait | io_wq_put_hash | io-wq.h | declared in param, used in body |
| io_wq_hash | io-wq.h | map, refs, wait | io_wq_put_hash | io_uring.c | declared in param, used in body |
| io_wq_hash | io-wq.h | map, refs, wait | io_init_wq_offload | tctx.c | used in body |
| io_wq_data | io-wq.h | do_work, free_work, hash, task | io_wq_hash_wake | io-wq.c | used in body |
| io_wq_data | io-wq.h | do_work, free_work, hash, task | io_wq_create | io-wq.c | declared in param |
| io_wq_data | io-wq.h | do_work, free_work, hash, task | io_wq_create | io-wq.h | declared in param |
| io_wq_data | io-wq.h | do_work, free_work, hash, task | io_wq_create | tctx.c | declared in param |
| io_wq_data | io-wq.h | do_work, free_work, hash, task | io_wq_put_hash | io-wq.c | used in body |
| io_wq_data | io-wq.h | do_work, free_work, hash, task | io_wq_put_hash | io-wq.h | used in body |
| io_wq_data | io-wq.h | do_work, free_work, hash, task | io_wq_put_hash | io_uring.c | used in body |
| io_wq_data | io-wq.h | do_work, free_work, hash, task | io_init_wq_offload | tctx.c | initialized, used in body |
| io_defer_entry | io_uring.c | list, req, seq | io_queue_deferred | io_uring.c | used in body |
| io_defer_entry | io_uring.c | list, req, seq | io_get_sequence | io_uring.c | used in body |
| io_defer_entry | io_uring.c | list, req, seq | io_cancel_defer_files | io_uring.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | io_cqring_schedule_timeout | io_uring.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | __io_cqring_wait_schedule | io_uring.c | declared in param, used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | io_cqring_wait_schedule | io_uring.c | declared in param, used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | io_cqring_wait | io_uring.c | declared in param, used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | io_validate_ext_arg | io_uring.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | io_get_ext_arg | io_uring.c | declared in param, used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | advise.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | alloc_cache.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | alloc_cache.h | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | cancel.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | cancel.h | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | epoll.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | eventfd.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | fdinfo.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | filetable.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | fs.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | futex.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | io-wq.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | io-wq.h | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | io_uring.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | io_uring.h | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | kbuf.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | kbuf.h | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | memmap.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | msg_ring.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | napi.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | napi.h | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | net.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | nop.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | notif.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | notif.h | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | opdef.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | openclose.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | poll.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | refs.h | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | register.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | rsrc.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | rsrc.h | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | rw.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | slist.h | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | splice.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | sqpoll.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | statx.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | sync.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | tctx.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | tctx.h | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | timeout.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | timeout.h | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | truncate.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | uring_cmd.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | waitid.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | xattr.c | used in body |
| ext_arg | io_uring.c | argsz, iowait, min_time, sig, ts, ts_set | if | zcrx.c | used in body |
| io_tctx_exit | io_uring.c | completion, ctx, task_work | io_uring_poll | io_uring.c | used in body |
| io_tctx_exit | io_uring.c | completion, ctx, task_work | io_tctx_exit_cb | io_uring.c | used in body |
| io_tctx_exit | io_uring.c | completion, ctx, task_work | io_ring_exit_work | io_uring.c | initialized, used in body |
| io_tctx_exit | io_uring.c | completion, ctx, task_work | io_ring_exit_work | sqpoll.c | initialized, used in body |
| io_task_cancel | io_uring.c | all, tctx | io_uring_release | io_uring.c | used in body |
| io_task_cancel | io_uring.c | all, tctx | io_cancel_task_cb | io_uring.c | used in body |
| io_task_cancel | io_uring.c | all, tctx | io_uring_try_cancel_requests | io_uring.c | used in body |
| io_wait_queue | io_uring.h | CONFIG_NET_RX_BUSY_POLL, cq_min_tail, cq_tail, ctx, endif, hit_timeout, min_timeout, napi_busy_poll_dt, napi_prefer_busy_poll, nr_timeouts, t, timeout, wq | io_wake_function | io_uring.c | used in body |
| io_wait_queue | io_uring.h | CONFIG_NET_RX_BUSY_POLL, cq_min_tail, cq_tail, ctx, endif, hit_timeout, min_timeout, napi_busy_poll_dt, napi_prefer_busy_poll, nr_timeouts, t, timeout, wq | io_cqring_timer_wakeup | io_uring.c | used in body |
| io_wait_queue | io_uring.h | CONFIG_NET_RX_BUSY_POLL, cq_min_tail, cq_tail, ctx, endif, hit_timeout, min_timeout, napi_busy_poll_dt, napi_prefer_busy_poll, nr_timeouts, t, timeout, wq | io_cqring_min_timer_wakeup | io_uring.c | used in body |
| io_wait_queue | io_uring.h | CONFIG_NET_RX_BUSY_POLL, cq_min_tail, cq_tail, ctx, endif, hit_timeout, min_timeout, napi_busy_poll_dt, napi_prefer_busy_poll, nr_timeouts, t, timeout, wq | io_cqring_schedule_timeout | io_uring.c | declared in param, used in body |
| io_wait_queue | io_uring.h | CONFIG_NET_RX_BUSY_POLL, cq_min_tail, cq_tail, ctx, endif, hit_timeout, min_timeout, napi_busy_poll_dt, napi_prefer_busy_poll, nr_timeouts, t, timeout, wq | __io_cqring_wait_schedule | io_uring.c | declared in param, used in body |
| io_wait_queue | io_uring.h | CONFIG_NET_RX_BUSY_POLL, cq_min_tail, cq_tail, ctx, endif, hit_timeout, min_timeout, napi_busy_poll_dt, napi_prefer_busy_poll, nr_timeouts, t, timeout, wq | io_cqring_wait_schedule | io_uring.c | declared in param |
| io_wait_queue | io_uring.h | CONFIG_NET_RX_BUSY_POLL, cq_min_tail, cq_tail, ctx, endif, hit_timeout, min_timeout, napi_busy_poll_dt, napi_prefer_busy_poll, nr_timeouts, t, timeout, wq | io_cqring_wait | io_uring.c | initialized, used in body |
| io_wait_queue | io_uring.h | CONFIG_NET_RX_BUSY_POLL, cq_min_tail, cq_tail, ctx, endif, hit_timeout, min_timeout, napi_busy_poll_dt, napi_prefer_busy_poll, nr_timeouts, t, timeout, wq | io_should_wake | io_uring.c | declared in param |
| io_wait_queue | io_uring.h | CONFIG_NET_RX_BUSY_POLL, cq_min_tail, cq_tail, ctx, endif, hit_timeout, min_timeout, napi_busy_poll_dt, napi_prefer_busy_poll, nr_timeouts, t, timeout, wq | io_should_wake | io_uring.h | declared in param |
| io_wait_queue | io_uring.h | CONFIG_NET_RX_BUSY_POLL, cq_min_tail, cq_tail, ctx, endif, hit_timeout, min_timeout, napi_busy_poll_dt, napi_prefer_busy_poll, nr_timeouts, t, timeout, wq | io_should_wake | napi.c | declared in param |
| io_wait_queue | io_uring.h | CONFIG_NET_RX_BUSY_POLL, cq_min_tail, cq_tail, ctx, endif, hit_timeout, min_timeout, napi_busy_poll_dt, napi_prefer_busy_poll, nr_timeouts, t, timeout, wq | io_napi_busy_loop_should_end | napi.c | used in body |
| io_wait_queue | io_uring.h | CONFIG_NET_RX_BUSY_POLL, cq_min_tail, cq_tail, ctx, endif, hit_timeout, min_timeout, napi_busy_poll_dt, napi_prefer_busy_poll, nr_timeouts, t, timeout, wq | io_napi_blocking_busy_loop | napi.c | declared in param |
| io_wait_queue | io_uring.h | CONFIG_NET_RX_BUSY_POLL, cq_min_tail, cq_tail, ctx, endif, hit_timeout, min_timeout, napi_busy_poll_dt, napi_prefer_busy_poll, nr_timeouts, t, timeout, wq | io_unregister_napi | napi.c | used in body |
| io_wait_queue | io_uring.h | CONFIG_NET_RX_BUSY_POLL, cq_min_tail, cq_tail, ctx, endif, hit_timeout, min_timeout, napi_busy_poll_dt, napi_prefer_busy_poll, nr_timeouts, t, timeout, wq | io_unregister_napi | napi.h | used in body |
| io_wait_queue | io_uring.h | CONFIG_NET_RX_BUSY_POLL, cq_min_tail, cq_tail, ctx, endif, hit_timeout, min_timeout, napi_busy_poll_dt, napi_prefer_busy_poll, nr_timeouts, t, timeout, wq | io_unregister_napi | register.c | used in body |
| io_wait_queue | io_uring.h | CONFIG_NET_RX_BUSY_POLL, cq_min_tail, cq_tail, ctx, endif, hit_timeout, min_timeout, napi_busy_poll_dt, napi_prefer_busy_poll, nr_timeouts, t, timeout, wq | __io_napi_busy_loop | napi.c | declared in param |
| io_wait_queue | io_uring.h | CONFIG_NET_RX_BUSY_POLL, cq_min_tail, cq_tail, ctx, endif, hit_timeout, min_timeout, napi_busy_poll_dt, napi_prefer_busy_poll, nr_timeouts, t, timeout, wq | __io_napi_busy_loop | napi.h | declared in param |
| io_wait_queue | io_uring.h | CONFIG_NET_RX_BUSY_POLL, cq_min_tail, cq_tail, ctx, endif, hit_timeout, min_timeout, napi_busy_poll_dt, napi_prefer_busy_poll, nr_timeouts, t, timeout, wq | io_napi | napi.h | used in body |
| io_wait_queue | io_uring.h | CONFIG_NET_RX_BUSY_POLL, cq_min_tail, cq_tail, ctx, endif, hit_timeout, min_timeout, napi_busy_poll_dt, napi_prefer_busy_poll, nr_timeouts, t, timeout, wq | io_napi | sqpoll.c | used in body |
| io_wait_queue | io_uring.h | CONFIG_NET_RX_BUSY_POLL, cq_min_tail, cq_tail, ctx, endif, hit_timeout, min_timeout, napi_busy_poll_dt, napi_prefer_busy_poll, nr_timeouts, t, timeout, wq | io_napi_busy_loop | io_uring.c | declared in param |
| io_wait_queue | io_uring.h | CONFIG_NET_RX_BUSY_POLL, cq_min_tail, cq_tail, ctx, endif, hit_timeout, min_timeout, napi_busy_poll_dt, napi_prefer_busy_poll, nr_timeouts, t, timeout, wq | io_napi_busy_loop | napi.h | declared in param |
| io_wait_queue | io_uring.h | CONFIG_NET_RX_BUSY_POLL, cq_min_tail, cq_tail, ctx, endif, hit_timeout, min_timeout, napi_busy_poll_dt, napi_prefer_busy_poll, nr_timeouts, t, timeout, wq | io_napi_add | napi.h | used in body |
| io_wait_queue | io_uring.h | CONFIG_NET_RX_BUSY_POLL, cq_min_tail, cq_tail, ctx, endif, hit_timeout, min_timeout, napi_busy_poll_dt, napi_prefer_busy_poll, nr_timeouts, t, timeout, wq | io_napi_add | poll.c | used in body |
| io_wait_queue | io_uring.h | CONFIG_NET_RX_BUSY_POLL, cq_min_tail, cq_tail, ctx, endif, hit_timeout, min_timeout, napi_busy_poll_dt, napi_prefer_busy_poll, nr_timeouts, t, timeout, wq | io_napi_busy_loop | io_uring.c | declared in param |
| io_wait_queue | io_uring.h | CONFIG_NET_RX_BUSY_POLL, cq_min_tail, cq_tail, ctx, endif, hit_timeout, min_timeout, napi_busy_poll_dt, napi_prefer_busy_poll, nr_timeouts, t, timeout, wq | io_napi_busy_loop | napi.h | declared in param |
| io_provide_buf | kbuf.c | addr, bgid, bid, file, len, nbufs | io_remove_buffers_prep | kbuf.c | used in body |
| io_provide_buf | kbuf.c | addr, bgid, bid, file, len, nbufs | io_remove_buffers_prep | kbuf.h | used in body |
| io_provide_buf | kbuf.c | addr, bgid, bid, file, len, nbufs | io_remove_buffers | kbuf.c | used in body |
| io_provide_buf | kbuf.c | addr, bgid, bid, file, len, nbufs | io_remove_buffers | kbuf.h | used in body |
| io_provide_buf | kbuf.c | addr, bgid, bid, file, len, nbufs | io_provide_buffers_prep | kbuf.c | used in body |
| io_provide_buf | kbuf.c | addr, bgid, bid, file, len, nbufs | io_provide_buffers_prep | kbuf.h | used in body |
| io_provide_buf | kbuf.c | addr, bgid, bid, file, len, nbufs | io_add_buffers | kbuf.c | declared in param |
| io_provide_buf | kbuf.c | addr, bgid, bid, file, len, nbufs | io_provide_buffers | kbuf.c | used in body |
| io_provide_buf | kbuf.c | addr, bgid, bid, file, len, nbufs | io_provide_buffers | kbuf.h | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_kbuf_inc_commit | kbuf.c | declared in param, used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_kbuf_commit | kbuf.c | declared in param, used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_kbuf_commit | kbuf.h | declared in param, used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_buffer_get_list | kbuf.c | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_buffer_add_list | kbuf.c | declared in param |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_kbuf_recycle_legacy | kbuf.c | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_kbuf_recycle_legacy | kbuf.h | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_provided_buffer_select | kbuf.c | declared in param, used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_provided_buffers_select | kbuf.c | declared in param, used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_ring_buffer_select | kbuf.c | declared in param |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_buffer_select | kbuf.c | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_buffer_select | kbuf.h | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_buffer_select | net.c | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_buffer_select | rw.c | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_ring_buffers_peek | kbuf.c | declared in param |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_buffers_select | kbuf.c | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_buffers_select | kbuf.h | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_buffers_select | net.c | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_buffers_peek | kbuf.c | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_buffers_peek | kbuf.h | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_buffers_peek | net.c | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | __io_put_kbuf_ring | kbuf.c | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | __io_put_kbufs | kbuf.c | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | __io_put_kbufs | kbuf.h | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | __io_remove_buffers | kbuf.c | declared in param, used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_put_bl | kbuf.c | declared in param |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_destroy_buffers | io_uring.c | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_destroy_buffers | kbuf.c | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_destroy_buffers | kbuf.h | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_destroy_bl | kbuf.c | declared in param |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_remove_buffers | kbuf.c | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_remove_buffers | kbuf.h | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_provide_buffers_prep | kbuf.c | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_provide_buffers_prep | kbuf.h | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_add_buffers | kbuf.c | declared in param |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_provide_buffers | kbuf.c | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_provide_buffers | kbuf.h | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_register_pbuf_ring | kbuf.c | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_register_pbuf_ring | kbuf.h | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_register_pbuf_ring | register.c | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_unregister_pbuf_ring | kbuf.c | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_unregister_pbuf_ring | kbuf.h | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_unregister_pbuf_ring | register.c | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_register_pbuf_status | kbuf.c | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_register_pbuf_status | kbuf.h | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_register_pbuf_status | register.c | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_pbuf_get_region | kbuf.c | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_pbuf_get_region | kbuf.h | used in body |
| io_buffer_list | kbuf.h | buf_list, buf_ring, not, set, union, used | io_pbuf_get_region | memmap.c | used in body |
| io_buffer | kbuf.h | addr, bgid, bid, len, list | io_kbuf_recycle_legacy | kbuf.c | used in body |
| io_buffer | kbuf.h | addr, bgid, bid, len, list | io_kbuf_recycle_legacy | kbuf.h | used in body |
| io_buffer | kbuf.h | addr, bgid, bid, len, list | io_provided_buffer_select | kbuf.c | used in body |
| io_buffer | kbuf.h | addr, bgid, bid, len, list | __io_remove_buffers | kbuf.c | used in body |
| io_buffer | kbuf.h | addr, bgid, bid, len, list | io_add_buffers | kbuf.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | io_buffer_select | kbuf.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | io_buffer_select | kbuf.h | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | io_buffer_select | net.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | io_buffer_select | rw.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | io_ring_buffers_peek | kbuf.c | declared in param |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | advise.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | alloc_cache.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | alloc_cache.h | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | cancel.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | cancel.h | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | epoll.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | eventfd.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | fdinfo.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | filetable.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | fs.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | futex.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | io-wq.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | io-wq.h | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | io_uring.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | io_uring.h | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | kbuf.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | kbuf.h | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | memmap.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | msg_ring.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | napi.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | napi.h | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | net.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | nop.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | notif.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | notif.h | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | opdef.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | openclose.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | poll.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | refs.h | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | register.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | rsrc.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | rsrc.h | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | rw.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | slist.h | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | splice.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | sqpoll.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | statx.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | sync.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | tctx.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | tctx.h | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | timeout.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | timeout.h | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | truncate.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | uring_cmd.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | waitid.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | xattr.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | if | zcrx.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | io_buffers_select | kbuf.c | declared in param, used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | io_buffers_select | kbuf.h | declared in param, used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | io_buffers_select | net.c | declared in param, used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | io_buffers_peek | kbuf.c | declared in param |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | io_buffers_peek | kbuf.h | declared in param |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | io_buffers_peek | net.c | declared in param |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | io_send_select_buffer | net.c | used in body |
| buf_sel_arg | kbuf.h | iovs, max_len, mode, nr_iovs, out_len | io_recv_buf_select | net.c | used in body |
| io_msg | msg_ring.c | cmd, cqe_flags, dst_fd, file, len, src_fd, src_file, tw, union, user_data | io_msg_ring_cleanup | msg_ring.c | used in body |
| io_msg | msg_ring.c | cmd, cqe_flags, dst_fd, file, len, src_fd, src_file, tw, union, user_data | io_msg_ring_cleanup | msg_ring.h | used in body |
| io_msg | msg_ring.c | cmd, cqe_flags, dst_fd, file, len, src_fd, src_file, tw, union, user_data | io_msg_get_kiocb | msg_ring.c | used in body |
| io_msg | msg_ring.c | cmd, cqe_flags, dst_fd, file, len, src_fd, src_file, tw, union, user_data | io_msg_data_remote | msg_ring.c | declared in param, used in body |
| io_msg | msg_ring.c | cmd, cqe_flags, dst_fd, file, len, src_fd, src_file, tw, union, user_data | __io_msg_ring_data | msg_ring.c | declared in param |
| io_msg | msg_ring.c | cmd, cqe_flags, dst_fd, file, len, src_fd, src_file, tw, union, user_data | io_msg_ring_data | msg_ring.c | used in body |
| io_msg | msg_ring.c | cmd, cqe_flags, dst_fd, file, len, src_fd, src_file, tw, union, user_data | io_msg_grab_file | msg_ring.c | used in body |
| io_msg | msg_ring.c | cmd, cqe_flags, dst_fd, file, len, src_fd, src_file, tw, union, user_data | io_msg_install_complete | msg_ring.c | used in body |
| io_msg | msg_ring.c | cmd, cqe_flags, dst_fd, file, len, src_fd, src_file, tw, union, user_data | io_msg_tw_fd_complete | msg_ring.c | used in body |
| io_msg | msg_ring.c | cmd, cqe_flags, dst_fd, file, len, src_fd, src_file, tw, union, user_data | io_msg_fd_remote | msg_ring.c | used in body |
| io_msg | msg_ring.c | cmd, cqe_flags, dst_fd, file, len, src_fd, src_file, tw, union, user_data | io_msg_send_fd | msg_ring.c | used in body |
| io_msg | msg_ring.c | cmd, cqe_flags, dst_fd, file, len, src_fd, src_file, tw, union, user_data | __io_msg_ring_prep | msg_ring.c | declared in param |
| io_msg | msg_ring.c | cmd, cqe_flags, dst_fd, file, len, src_fd, src_file, tw, union, user_data | io_msg_ring_prep | msg_ring.c | used in body |
| io_msg | msg_ring.c | cmd, cqe_flags, dst_fd, file, len, src_fd, src_file, tw, union, user_data | io_msg_ring_prep | msg_ring.h | used in body |
| io_msg | msg_ring.c | cmd, cqe_flags, dst_fd, file, len, src_fd, src_file, tw, union, user_data | io_msg_ring | msg_ring.c | used in body |
| io_msg | msg_ring.c | cmd, cqe_flags, dst_fd, file, len, src_fd, src_file, tw, union, user_data | io_msg_ring | msg_ring.h | used in body |
| io_msg | msg_ring.c | cmd, cqe_flags, dst_fd, file, len, src_fd, src_file, tw, union, user_data | io_uring_sync_msg_ring | msg_ring.c | used in body |
| io_msg | msg_ring.c | cmd, cqe_flags, dst_fd, file, len, src_fd, src_file, tw, union, user_data | io_uring_sync_msg_ring | msg_ring.h | used in body |
| io_msg | msg_ring.c | cmd, cqe_flags, dst_fd, file, len, src_fd, src_file, tw, union, user_data | io_uring_sync_msg_ring | register.c | used in body |
| io_napi_entry | napi.c | list, napi_id, node, rcu, timeout | io_napi_hash_find | napi.c | used in body |
| io_napi_entry | napi.c | list, napi_id, node, rcu, timeout | __io_napi_add_id | napi.c | used in body |
| io_napi_entry | napi.c | list, napi_id, node, rcu, timeout | __io_napi_add_id | napi.h | used in body |
| io_napi_entry | napi.c | list, napi_id, node, rcu, timeout | __io_napi_del_id | napi.c | used in body |
| io_napi_entry | napi.c | list, napi_id, node, rcu, timeout | __io_napi_remove_stale | napi.c | used in body |
| io_napi_entry | napi.c | list, napi_id, node, rcu, timeout | io_napi_busy_loop_should_end | napi.c | used in body |
| io_napi_entry | napi.c | list, napi_id, node, rcu, timeout | io_napi_free | io_uring.c | used in body |
| io_napi_entry | napi.c | list, napi_id, node, rcu, timeout | io_napi_free | napi.c | used in body |
| io_napi_entry | napi.c | list, napi_id, node, rcu, timeout | io_napi_free | napi.h | used in body |
| io_shutdown | net.c | file, how | io_shutdown_prep | net.c | used in body |
| io_shutdown | net.c | file, how | io_shutdown_prep | net.h | used in body |
| io_shutdown | net.c | file, how | io_shutdown | net.c | used in body |
| io_shutdown | net.c | file, how | io_shutdown | net.h | used in body |
| io_shutdown | net.c | file, how | io_eopnotsupp_prep | opdef.c | used in body |
| io_accept | net.c | addr, addr_len, file, file_slot, flags, iou_flags, nofile | io_accept_prep | net.c | used in body |
| io_accept | net.c | addr, addr_len, file, file_slot, flags, iou_flags, nofile | io_accept_prep | net.h | used in body |
| io_accept | net.c | addr, addr_len, file, file_slot, flags, iou_flags, nofile | io_accept | net.c | used in body |
| io_accept | net.c | addr, addr_len, file, file_slot, flags, iou_flags, nofile | io_accept | net.h | used in body |
| io_accept | net.c | addr, addr_len, file, file_slot, flags, iou_flags, nofile | io_eopnotsupp_prep | opdef.c | used in body |
| io_socket | net.c | domain, file, file_slot, flags, nofile, protocol, type | io_socket_prep | net.c | used in body |
| io_socket | net.c | domain, file, file_slot, flags, nofile, protocol, type | io_socket_prep | net.h | used in body |
| io_socket | net.c | domain, file, file_slot, flags, nofile, protocol, type | io_socket | net.c | used in body |
| io_socket | net.c | domain, file, file_slot, flags, nofile, protocol, type | io_socket | net.h | used in body |
| io_socket | net.c | domain, file, file_slot, flags, nofile, protocol, type | io_eopnotsupp_prep | opdef.c | used in body |
| io_connect | net.c | addr, addr_len, file, in_progress, seen_econnaborted | io_connect_prep | net.c | used in body |
| io_connect | net.c | addr, addr_len, file, in_progress, seen_econnaborted | io_connect_prep | net.h | used in body |
| io_connect | net.c | addr, addr_len, file, in_progress, seen_econnaborted | io_connect | net.c | used in body |
| io_connect | net.c | addr, addr_len, file, in_progress, seen_econnaborted | io_connect | net.h | used in body |
| io_connect | net.c | addr, addr_len, file, in_progress, seen_econnaborted | io_eopnotsupp_prep | opdef.c | used in body |
| io_bind | net.c | addr_len, file | io_bind_prep | net.c | used in body |
| io_bind | net.c | addr_len, file | io_bind_prep | net.h | used in body |
| io_bind | net.c | addr_len, file | io_bind | net.c | used in body |
| io_bind | net.c | addr_len, file | io_bind | net.h | used in body |
| io_bind | net.c | addr_len, file | io_eopnotsupp_prep | opdef.c | used in body |
| io_listen | net.c | backlog, file | io_listen_prep | net.c | used in body |
| io_listen | net.c | backlog, file | io_listen_prep | net.h | used in body |
| io_listen | net.c | backlog, file | io_listen | net.c | used in body |
| io_listen | net.c | backlog, file | io_listen | net.h | used in body |
| io_listen | net.c | backlog, file | io_eopnotsupp_prep | opdef.c | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_mshot_prep_retry | net.c | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_compat_msg_copy_hdr | net.c | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_msg_copy_hdr | net.c | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_send_setup | net.c | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_sendmsg_setup | net.c | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_sendmsg_prep | net.c | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_sendmsg_prep | net.h | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_send_finish | net.c | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_sendmsg | net.c | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_sendmsg | net.h | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_send_select_buffer | net.c | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_send | net.c | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_send | net.h | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_recvmsg_prep_setup | net.c | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_recvmsg_prep | net.c | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_recvmsg_prep | net.h | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_recv_finish | net.c | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_recvmsg_prep_multishot | net.c | declared in param, used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_recvmsg_multishot | net.c | declared in param |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_recvmsg | net.c | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_recvmsg | net.h | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_recv_buf_select | net.c | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_recv | net.c | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_recv | net.h | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_send_zc_cleanup | net.c | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_send_zc_cleanup | net.h | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_send_zc_prep | net.c | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_send_zc_prep | net.h | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_send_zc_import | net.c | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_send_zc | net.c | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_send_zc | net.h | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_sendmsg_zc | net.c | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_sendmsg_zc | net.h | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_sendrecv_fail | net.c | used in body |
| io_sr_msg | net.c | buf, file, umsg, umsg_compat, union | io_sendrecv_fail | net.h | used in body |
| io_recvzc | net.c | file, flags, ifq, len, msg_flags | io_recvzc_prep | net.c | used in body |
| io_recvzc | net.c | file, flags, ifq, len, msg_flags | io_recvzc_prep | zcrx.h | used in body |
| io_recvzc | net.c | file, flags, ifq, len, msg_flags | io_recvzc | net.c | used in body |
| io_recvzc | net.c | file, flags, ifq, len, msg_flags | io_recvzc | zcrx.h | used in body |
| io_recvzc | net.c | file, flags, ifq, len, msg_flags | io_eopnotsupp_prep | opdef.c | used in body |
| io_recvzc | net.c | file, flags, ifq, len, msg_flags | io_zcrx_recv | net.c | used in body |
| io_recvzc | net.c | file, flags, ifq, len, msg_flags | io_zcrx_recv | zcrx.c | used in body |
| io_recvzc | net.c | file, flags, ifq, len, msg_flags | io_zcrx_recv | zcrx.h | used in body |
| io_recvmsg_multishot_hdr | net.c | addr, msg | io_recvmsg_prep_multishot | net.c | used in body |
| io_recvmsg_multishot_hdr | net.c | addr, msg | io_recvmsg_multishot | net.c | initialized, used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_ring_ctx_alloc | io_uring.c | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_net_retry | net.c | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_netmsg_iovec_free | net.c | declared in param |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_netmsg_recycle | net.c | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_msg_alloc_async | net.c | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_mshot_prep_retry | net.c | declared in param, used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_net_import_vec | net.c | declared in param, used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_compat_msg_copy_hdr | net.c | declared in param |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_copy_msghdr_from_user | net.c | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_msg_copy_hdr | net.c | declared in param |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_sendmsg_recvmsg_cleanup | net.c | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_sendmsg_recvmsg_cleanup | net.h | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_send_setup | net.c | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_sendmsg_setup | net.c | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_req_msg_cleanup | net.c | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_bundle_nbufs | net.c | declared in param, used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_send_finish | net.c | declared in param |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_sendmsg | net.c | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_sendmsg | net.h | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_send_select_buffer | net.c | declared in param |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_send | net.c | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_send | net.h | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_recvmsg_mshot_prep | net.c | declared in param, used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_recvmsg_copy_hdr | net.c | declared in param |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_recvmsg_prep_setup | net.c | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_recvmsg_prep | net.c | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_recvmsg_prep | net.h | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_recv_finish | net.c | declared in param, used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_recvmsg_prep_multishot | net.c | declared in param, used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_recvmsg_multishot | net.c | declared in param |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_recvmsg | net.c | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_recvmsg | net.h | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_recv_buf_select | net.c | declared in param |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_recv | net.c | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_recv | net.h | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_send_zc_cleanup | net.c | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_send_zc_cleanup | net.h | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_send_zc_prep | net.c | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_send_zc_prep | net.h | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_send_zc_import | net.c | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_send_zc | net.c | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_send_zc | net.h | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_sendmsg_zc | net.c | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_sendmsg_zc | net.h | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_connect_prep | net.c | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_connect_prep | net.h | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_connect | net.c | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_connect | net.h | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_bind_prep | net.c | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_bind_prep | net.h | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_bind | net.c | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_bind | net.h | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_netmsg_cache_free | net.c | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_netmsg_cache_free | net.h | used in body |
| io_async_msghdr | net.h | CONFIG_NET, addr, clear, controllen, else, endif, fast_iov, msg, namelen, payloadlen, uaddr, vec | io_eopnotsupp_prep | opdef.c | used in body |
| io_nop | nop.c | fd, file, flags, here, member, result | io_nop_prep | nop.c | used in body |
| io_nop | nop.c | fd, file, flags, here, member, result | io_nop_prep | nop.h | used in body |
| io_nop | nop.c | fd, file, flags, here, member, result | io_nop | nop.c | used in body |
| io_nop | nop.c | fd, file, flags, here, member, result | io_nop | nop.h | used in body |
| io_nop | nop.c | fd, file, flags, here, member, result | io_eopnotsupp_prep | opdef.c | used in body |
| io_notif_data | notif.h | account_pages, file, head, next, uarg, zc_copied, zc_report, zc_used | io_send_zc_prep | net.c | used in body |
| io_notif_data | notif.h | account_pages, file, head, next, uarg, zc_copied, zc_report, zc_used | io_send_zc_prep | net.h | used in body |
| io_notif_data | notif.h | account_pages, file, head, next, uarg, zc_copied, zc_report, zc_used | io_notif_tw_complete | notif.c | used in body |
| io_notif_data | notif.h | account_pages, file, head, next, uarg, zc_copied, zc_report, zc_used | io_tx_ubuf_complete | notif.c | used in body |
| io_notif_data | notif.h | account_pages, file, head, next, uarg, zc_copied, zc_report, zc_used | io_tx_ubuf_complete | notif.h | used in body |
| io_notif_data | notif.h | account_pages, file, head, next, uarg, zc_copied, zc_report, zc_used | io_link_skb | notif.c | used in body |
| io_notif_data | notif.h | account_pages, file, head, next, uarg, zc_copied, zc_report, zc_used | io_notif_to_data | net.c | used in body |
| io_notif_data | notif.h | account_pages, file, head, next, uarg, zc_copied, zc_report, zc_used | io_notif_to_data | notif.c | used in body |
| io_notif_data | notif.h | account_pages, file, head, next, uarg, zc_copied, zc_report, zc_used | io_notif_to_data | notif.h | used in body |
| io_notif_data | notif.h | account_pages, file, head, next, uarg, zc_copied, zc_report, zc_used | io_notif_account_mem | net.c | used in body |
| io_notif_data | notif.h | account_pages, file, head, next, uarg, zc_copied, zc_report, zc_used | io_notif_account_mem | notif.h | used in body |
| io_issue_def | opdef.h | 1, any, assigned, async_size, auditing, file, int, io_kiocb, io_uring_sqe, iopoll, ioprio, know, list, needed, opcode, plug, selection, vectored, wait | io_prep_async_work | io_uring.c | used in body |
| io_issue_def | opdef.h | 1, any, assigned, async_size, auditing, file, int, io_kiocb, io_uring_sqe, iopoll, ioprio, know, list, needed, opcode, plug, selection, vectored, wait | io_get_sequence | io_uring.c | used in body |
| io_issue_def | opdef.h | 1, any, assigned, async_size, auditing, file, int, io_kiocb, io_uring_sqe, iopoll, ioprio, know, list, needed, opcode, plug, selection, vectored, wait | io_assign_file | io_uring.c | declared in param, used in body |
| io_issue_def | opdef.h | 1, any, assigned, async_size, auditing, file, int, io_kiocb, io_uring_sqe, iopoll, ioprio, know, list, needed, opcode, plug, selection, vectored, wait | __io_issue_sqe | io_uring.c | declared in param |
| io_issue_def | opdef.h | 1, any, assigned, async_size, auditing, file, int, io_kiocb, io_uring_sqe, iopoll, ioprio, know, list, needed, opcode, plug, selection, vectored, wait | io_issue_sqe | io_uring.c | used in body |
| io_issue_def | opdef.h | 1, any, assigned, async_size, auditing, file, int, io_kiocb, io_uring_sqe, iopoll, ioprio, know, list, needed, opcode, plug, selection, vectored, wait | io_wq_submit_work | io_uring.c | used in body |
| io_issue_def | opdef.h | 1, any, assigned, async_size, auditing, file, int, io_kiocb, io_uring_sqe, iopoll, ioprio, know, list, needed, opcode, plug, selection, vectored, wait | io_wq_submit_work | io_uring.h | used in body |
| io_issue_def | opdef.h | 1, any, assigned, async_size, auditing, file, int, io_kiocb, io_uring_sqe, iopoll, ioprio, know, list, needed, opcode, plug, selection, vectored, wait | io_init_fail_req | io_uring.c | used in body |
| io_issue_def | opdef.h | 1, any, assigned, async_size, auditing, file, int, io_kiocb, io_uring_sqe, iopoll, ioprio, know, list, needed, opcode, plug, selection, vectored, wait | io_uring_alloc_async_data | io_uring.h | used in body |
| io_issue_def | opdef.h | 1, any, assigned, async_size, auditing, file, int, io_kiocb, io_uring_sqe, iopoll, ioprio, know, list, needed, opcode, plug, selection, vectored, wait | io_uring_alloc_async_data | net.c | used in body |
| io_issue_def | opdef.h | 1, any, assigned, async_size, auditing, file, int, io_kiocb, io_uring_sqe, iopoll, ioprio, know, list, needed, opcode, plug, selection, vectored, wait | io_uring_alloc_async_data | rw.c | used in body |
| io_issue_def | opdef.h | 1, any, assigned, async_size, auditing, file, int, io_kiocb, io_uring_sqe, iopoll, ioprio, know, list, needed, opcode, plug, selection, vectored, wait | io_uring_alloc_async_data | timeout.c | used in body |
| io_issue_def | opdef.h | 1, any, assigned, async_size, auditing, file, int, io_kiocb, io_uring_sqe, iopoll, ioprio, know, list, needed, opcode, plug, selection, vectored, wait | io_uring_alloc_async_data | uring_cmd.c | used in body |
| io_issue_def | opdef.h | 1, any, assigned, async_size, auditing, file, int, io_kiocb, io_uring_sqe, iopoll, ioprio, know, list, needed, opcode, plug, selection, vectored, wait | io_uring_alloc_async_data | waitid.c | used in body |
| io_issue_def | opdef.h | 1, any, assigned, async_size, auditing, file, int, io_kiocb, io_uring_sqe, iopoll, ioprio, know, list, needed, opcode, plug, selection, vectored, wait | io_eopnotsupp_prep | opdef.c | used in body |
| io_issue_def | opdef.h | 1, any, assigned, async_size, auditing, file, int, io_kiocb, io_uring_sqe, iopoll, ioprio, know, list, needed, opcode, plug, selection, vectored, wait | io_arm_poll_handler | io_uring.c | used in body |
| io_issue_def | opdef.h | 1, any, assigned, async_size, auditing, file, int, io_kiocb, io_uring_sqe, iopoll, ioprio, know, list, needed, opcode, plug, selection, vectored, wait | io_arm_poll_handler | poll.c | used in body |
| io_issue_def | opdef.h | 1, any, assigned, async_size, auditing, file, int, io_kiocb, io_uring_sqe, iopoll, ioprio, know, list, needed, opcode, plug, selection, vectored, wait | io_arm_poll_handler | poll.h | used in body |
| io_issue_def | opdef.h | 1, any, assigned, async_size, auditing, file, int, io_kiocb, io_uring_sqe, iopoll, ioprio, know, list, needed, opcode, plug, selection, vectored, wait | __io_import_rw_buffer | rw.c | used in body |
| io_cold_def | opdef.h | io_kiocb, name | io_clean_op | io_uring.c | used in body |
| io_cold_def | opdef.h | io_kiocb, name | io_req_complete_post | io_uring.c | used in body |
| io_cold_def | opdef.h | io_kiocb, name | io_eopnotsupp_prep | opdef.c | used in body |
| io_open | openclose.c | dfd, file, file_slot, filename, how, nofile | io_openat_force_async | openclose.c | declared in param |
| io_open | openclose.c | dfd, file, file_slot, filename, how, nofile | __io_openat_prep | openclose.c | used in body |
| io_open | openclose.c | dfd, file, file_slot, filename, how, nofile | io_openat_prep | openclose.c | used in body |
| io_open | openclose.c | dfd, file, file_slot, filename, how, nofile | io_openat_prep | openclose.h | used in body |
| io_open | openclose.c | dfd, file, file_slot, filename, how, nofile | io_openat2_prep | openclose.c | used in body |
| io_open | openclose.c | dfd, file, file_slot, filename, how, nofile | io_openat2_prep | openclose.h | used in body |
| io_open | openclose.c | dfd, file, file_slot, filename, how, nofile | io_openat2 | openclose.c | used in body |
| io_open | openclose.c | dfd, file, file_slot, filename, how, nofile | io_openat2 | openclose.h | used in body |
| io_open | openclose.c | dfd, file, file_slot, filename, how, nofile | io_open_cleanup | openclose.c | used in body |
| io_open | openclose.c | dfd, file, file_slot, filename, how, nofile | io_open_cleanup | openclose.h | used in body |
| io_close | openclose.c | fd, file, file_slot | io_eopnotsupp_prep | opdef.c | used in body |
| io_close | openclose.c | fd, file, file_slot | io_close_fixed | openclose.c | used in body |
| io_close | openclose.c | fd, file, file_slot | io_close_prep | openclose.c | used in body |
| io_close | openclose.c | fd, file, file_slot | io_close_prep | openclose.h | used in body |
| io_close | openclose.c | fd, file, file_slot | io_close | openclose.c | used in body |
| io_close | openclose.c | fd, file, file_slot | io_close | openclose.h | used in body |
| io_fixed_install | openclose.c | file, o_flags | io_install_fixed_fd_prep | openclose.c | used in body |
| io_fixed_install | openclose.c | file, o_flags | io_install_fixed_fd_prep | openclose.h | used in body |
| io_fixed_install | openclose.c | file, o_flags | io_install_fixed_fd | openclose.c | used in body |
| io_fixed_install | openclose.c | file, o_flags | io_install_fixed_fd | openclose.h | used in body |
| io_poll_update | poll.c | events, file, new_user_data, old_user_data, update_events, update_user_data | io_poll_remove_prep | poll.c | used in body |
| io_poll_update | poll.c | events, file, new_user_data, old_user_data, update_events, update_user_data | io_poll_remove_prep | poll.h | used in body |
| io_poll_update | poll.c | events, file, new_user_data, old_user_data, update_events, update_user_data | io_poll_remove | poll.c | used in body |
| io_poll_update | poll.c | events, file, new_user_data, old_user_data, update_events, update_user_data | io_poll_remove | poll.h | used in body |
| io_poll_table | poll.c | 0, error, nr_entries, owning, pt, req, result_mask, value | io_poll_double_prepare | poll.c | used in body |
| io_poll_table | poll.c | 0, error, nr_entries, owning, pt, req, result_mask, value | __io_queue_proc | poll.c | declared in param |
| io_poll_table | poll.c | 0, error, nr_entries, owning, pt, req, result_mask, value | io_poll_queue_proc | poll.c | used in body |
| io_poll_table | poll.c | 0, error, nr_entries, owning, pt, req, result_mask, value | io_poll_can_finish_inline | poll.c | declared in param |
| io_poll_table | poll.c | 0, error, nr_entries, owning, pt, req, result_mask, value | io_poll_add_hash | poll.c | used in body |
| io_poll_table | poll.c | 0, error, nr_entries, owning, pt, req, result_mask, value | __io_arm_poll_handler | poll.c | declared in param |
| io_poll_table | poll.c | 0, error, nr_entries, owning, pt, req, result_mask, value | io_async_queue_proc | poll.c | used in body |
| io_poll_table | poll.c | 0, error, nr_entries, owning, pt, req, result_mask, value | io_arm_poll_handler | io_uring.c | initialized, used in body |
| io_poll_table | poll.c | 0, error, nr_entries, owning, pt, req, result_mask, value | io_arm_poll_handler | poll.c | initialized, used in body |
| io_poll_table | poll.c | 0, error, nr_entries, owning, pt, req, result_mask, value | io_arm_poll_handler | poll.h | initialized, used in body |
| io_poll_table | poll.c | 0, error, nr_entries, owning, pt, req, result_mask, value | io_poll_add | poll.c | initialized, used in body |
| io_poll_table | poll.c | 0, error, nr_entries, owning, pt, req, result_mask, value | io_poll_add | poll.h | initialized, used in body |
| io_poll | poll.h | events, file, head, retries, wait | io_poll_mark_cancelled | poll.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | io_poll_get_double | poll.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | io_poll_get_single | poll.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | io_poll_req_insert | poll.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | io_init_poll_iocb | poll.c | declared in param, used in body |
| io_poll | poll.h | events, file, head, retries, wait | io_poll_remove_entry | poll.c | declared in param |
| io_poll | poll.h | events, file, head, retries, wait | if | advise.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | alloc_cache.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | alloc_cache.h | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | cancel.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | cancel.h | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | epoll.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | eventfd.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | fdinfo.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | filetable.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | fs.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | futex.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | io-wq.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | io-wq.h | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | io_uring.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | io_uring.h | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | kbuf.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | kbuf.h | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | memmap.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | msg_ring.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | napi.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | napi.h | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | net.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | nop.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | notif.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | notif.h | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | opdef.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | openclose.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | poll.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | refs.h | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | register.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | rsrc.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | rsrc.h | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | rw.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | slist.h | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | splice.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | sqpoll.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | statx.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | sync.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | tctx.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | tctx.h | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | timeout.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | timeout.h | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | truncate.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | uring_cmd.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | waitid.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | xattr.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | if | zcrx.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | io_poll_cancel_req | poll.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | io_pollfree_wake | poll.c | declared in param |
| io_poll | poll.h | events, file, head, retries, wait | io_poll_wake | poll.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | io_poll_double_prepare | poll.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | __io_queue_proc | poll.c | declared in param, used in body |
| io_poll | poll.h | events, file, head, retries, wait | io_poll_queue_proc | poll.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | io_poll_add_hash | poll.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | __io_arm_poll_handler | poll.c | declared in param |
| io_poll | poll.h | events, file, head, retries, wait | io_poll_add_prep | poll.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | io_poll_add_prep | poll.h | used in body |
| io_poll | poll.h | events, file, head, retries, wait | io_poll_add | poll.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | io_poll_add | poll.h | used in body |
| io_poll | poll.h | events, file, head, retries, wait | io_poll_remove | poll.c | used in body |
| io_poll | poll.h | events, file, head, retries, wait | io_poll_remove | poll.h | used in body |
| async_poll | poll.h | double_poll, poll | io_ring_ctx_alloc | io_uring.c | used in body |
| async_poll | poll.h | double_poll, poll | io_queue_next | io_uring.c | used in body |
| async_poll | poll.h | double_poll, poll | io_queue_next | io_uring.h | used in body |
| async_poll | poll.h | double_poll, poll | io_queue_next | timeout.c | used in body |
| async_poll | poll.h | double_poll, poll | io_async_queue_proc | poll.c | used in body |
| async_poll | poll.h | double_poll, poll | io_req_alloc_apoll | poll.c | used in body |
| async_poll | poll.h | double_poll, poll | io_arm_poll_handler | io_uring.c | used in body |
| async_poll | poll.h | double_poll, poll | io_arm_poll_handler | poll.c | used in body |
| async_poll | poll.h | double_poll, poll | io_arm_poll_handler | poll.h | used in body |
| io_ring_ctx_rings | register.c | ring_region, rings, sq_region, sq_sqes | io_register_clock | register.c | used in body |
| io_ring_ctx_rings | register.c | ring_region, rings, sq_region, sq_sqes | io_register_free_rings | register.c | declared in param |
| io_ring_ctx_rings | register.c | ring_region, rings, sq_region, sq_sqes | io_register_resize_rings | register.c | used in body |
| io_rsrc_update | rsrc.c | arg, file, nr_args, offset | io_files_update_prep | rsrc.c | used in body |
| io_rsrc_update | rsrc.c | arg, file, nr_args, offset | io_files_update_prep | rsrc.h | used in body |
| io_rsrc_update | rsrc.c | arg, file, nr_args, offset | io_files_update_with_index_alloc | rsrc.c | used in body |
| io_rsrc_update | rsrc.c | arg, file, nr_args, offset | io_files_update | rsrc.c | used in body |
| io_rsrc_update | rsrc.c | arg, file, nr_args, offset | io_files_update | rsrc.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | __io_sync_cancel | cancel.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_free_file_tables | filetable.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_free_file_tables | filetable.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_free_file_tables | rsrc.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_fixed_fd_remove | filetable.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_fixed_fd_remove | filetable.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_fixed_fd_remove | openclose.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_file_bitmap_set | filetable.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_file_bitmap_set | filetable.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_file_bitmap_set | rsrc.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_slot_flags | filetable.h | declared in param, used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_slot_flags | io_uring.c | declared in param, used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_slot_file | cancel.c | declared in param, used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_slot_file | fdinfo.c | declared in param, used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_slot_file | filetable.h | declared in param, used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_slot_file | io_uring.c | declared in param, used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_slot_file | msg_ring.c | declared in param, used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_slot_file | rsrc.c | declared in param, used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_slot_file | splice.c | declared in param, used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_fixed_file_set | filetable.c | declared in param |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_fixed_file_set | filetable.h | declared in param |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_fixed_file_set | rsrc.c | declared in param |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_file_get_fixed | cancel.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_file_get_fixed | io_uring.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_file_get_fixed | io_uring.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_file_get_fixed | nop.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_msg_grab_file | msg_ring.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_buffer_unmap | rsrc.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_rsrc_node_alloc | filetable.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_rsrc_node_alloc | rsrc.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_rsrc_node_alloc | rsrc.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_rsrc_cache_init | io_uring.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_rsrc_cache_init | rsrc.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_rsrc_cache_init | rsrc.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_rsrc_data_alloc | filetable.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_rsrc_data_alloc | rsrc.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_rsrc_data_alloc | rsrc.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | __io_sqe_files_update | rsrc.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | __io_sqe_buffers_update | rsrc.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_files_update | rsrc.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_files_update | rsrc.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_free_rsrc_node | rsrc.c | declared in param |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_free_rsrc_node | rsrc.h | declared in param |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_sqe_files_register | register.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_sqe_files_register | rsrc.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_sqe_files_register | rsrc.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | headpage_already_acct | rsrc.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | advise.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | alloc_cache.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | alloc_cache.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | cancel.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | cancel.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | epoll.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | eventfd.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | fdinfo.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | filetable.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | fs.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | futex.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | io-wq.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | io-wq.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | io_uring.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | io_uring.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | kbuf.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | kbuf.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | memmap.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | msg_ring.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | napi.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | napi.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | net.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | nop.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | notif.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | notif.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | opdef.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | openclose.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | poll.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | refs.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | register.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | rsrc.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | rsrc.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | rw.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | slist.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | splice.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | sqpoll.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | statx.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | sync.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | tctx.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | tctx.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | timeout.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | timeout.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | truncate.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | uring_cmd.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | waitid.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | xattr.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | zcrx.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_sqe_buffer_register | rsrc.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_sqe_buffers_register | register.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_sqe_buffers_register | rsrc.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_sqe_buffers_register | rsrc.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_buffer_unregister_bvec | rsrc.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | advise.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | alloc_cache.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | alloc_cache.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | cancel.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | cancel.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | epoll.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | eventfd.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | fdinfo.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | filetable.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | fs.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | futex.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | io-wq.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | io-wq.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | io_uring.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | io_uring.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | kbuf.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | kbuf.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | memmap.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | msg_ring.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | napi.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | napi.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | net.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | nop.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | notif.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | notif.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | opdef.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | openclose.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | poll.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | refs.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | register.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | rsrc.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | rsrc.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | rw.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | slist.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | splice.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | sqpoll.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | statx.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | sync.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | tctx.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | tctx.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | timeout.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | timeout.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | truncate.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | uring_cmd.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | waitid.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | xattr.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | if | zcrx.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_find_buf_node | nop.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_find_buf_node | rsrc.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_find_buf_node | rsrc.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_import_reg_buf | net.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_import_reg_buf | rsrc.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_import_reg_buf | rsrc.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_import_reg_buf | rw.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_import_reg_buf | uring_cmd.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_clone_buffers | rsrc.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_import_reg_vec | net.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_import_reg_vec | rsrc.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_import_reg_vec | rsrc.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_import_reg_vec | rw.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_import_reg_vec | uring_cmd.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_rsrc_node_lookup | cancel.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_rsrc_node_lookup | filetable.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_rsrc_node_lookup | io_uring.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_rsrc_node_lookup | msg_ring.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_rsrc_node_lookup | rsrc.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_rsrc_node_lookup | rsrc.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_rsrc_node_lookup | splice.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_put_rsrc_node | rsrc.c | declared in param |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_put_rsrc_node | rsrc.h | declared in param |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_put_rsrc_node | splice.c | declared in param |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_reset_rsrc_node | filetable.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_reset_rsrc_node | rsrc.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_reset_rsrc_node | rsrc.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_req_put_rsrc_nodes | io_uring.c | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_req_put_rsrc_nodes | rsrc.h | used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_req_assign_rsrc_node | io_uring.c | declared in param, used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_req_assign_rsrc_node | rsrc.h | declared in param, used in body |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_req_assign_buf_node | rsrc.c | declared in param |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_req_assign_buf_node | rsrc.h | declared in param |
| io_rsrc_node | rsrc.h | buf, file_ptr, refs, tag, type, union | io_splice_get_file | splice.c | used in body |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | io_uring_show_fdinfo | fdinfo.c | used in body |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | io_uring_show_fdinfo | fdinfo.h | used in body |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | io_release_ubuf | rsrc.c | used in body |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | io_alloc_imu | rsrc.c | used in body |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | io_free_imu | rsrc.c | declared in param, used in body |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | io_buffer_unmap | rsrc.c | declared in param |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | io_rsrc_cache_init | io_uring.c | used in body |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | io_rsrc_cache_init | rsrc.c | used in body |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | io_rsrc_cache_init | rsrc.h | used in body |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | headpage_already_acct | rsrc.c | used in body |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | io_buffer_account_pin | rsrc.c | declared in param |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | io_sqe_buffer_register | rsrc.c | used in body |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | io_sqe_buffers_register | register.c | used in body |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | io_sqe_buffers_register | rsrc.c | used in body |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | io_sqe_buffers_register | rsrc.h | used in body |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | io_buffer_unregister_bvec | rsrc.c | used in body |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | validate_fixed_range | rsrc.c | declared in param, used in body |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | io_import_fixed | rsrc.c | declared in param |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | io_vec_realloc | rsrc.c | used in body |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | io_vec_realloc | rsrc.h | used in body |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | io_vec_fill_bvec | rsrc.c | declared in param, used in body |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | io_estimate_bvec_size | rsrc.c | declared in param, used in body |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | io_vec_fill_kern_bvec | rsrc.c | declared in param, used in body |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | iov_kern_bvec_size | rsrc.c | declared in param, used in body |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | io_kern_bvec_size | rsrc.c | declared in param |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | io_import_reg_vec | net.c | used in body |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | io_import_reg_vec | rsrc.c | used in body |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | io_import_reg_vec | rsrc.h | used in body |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | io_import_reg_vec | rw.c | used in body |
| io_mapped_ubuf | rsrc.h | acct_pages, dir, folio_shift, is_kbuf, len, nr_bvecs, priv, refs, ubuf, void | io_import_reg_vec | uring_cmd.c | used in body |
| io_imu_folio_data | rsrc.h | buf, folio_shift, folios, included, nr_folios, nr_pages_head, nr_pages_mid | io_region_init_ptr | memmap.c | initialized, used in body |
| io_imu_folio_data | rsrc.h | buf, folio_shift, folios, included, nr_folios, nr_pages_head, nr_pages_mid | io_buffer_account_pin | rsrc.c | used in body |
| io_imu_folio_data | rsrc.h | buf, folio_shift, folios, included, nr_folios, nr_pages_head, nr_pages_mid | io_coalesce_buffer | rsrc.c | declared in param, used in body |
| io_imu_folio_data | rsrc.h | buf, folio_shift, folios, included, nr_folios, nr_pages_head, nr_pages_mid | io_check_coalesce_buffer | memmap.c | declared in param |
| io_imu_folio_data | rsrc.h | buf, folio_shift, folios, included, nr_folios, nr_pages_head, nr_pages_mid | io_check_coalesce_buffer | rsrc.c | declared in param |
| io_imu_folio_data | rsrc.h | buf, folio_shift, folios, included, nr_folios, nr_pages_head, nr_pages_mid | io_check_coalesce_buffer | rsrc.h | declared in param |
| io_imu_folio_data | rsrc.h | buf, folio_shift, folios, included, nr_folios, nr_pages_head, nr_pages_mid | io_sqe_buffer_register | rsrc.c | initialized, used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_file_supports_nowait | rw.c | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_iov_compat_buffer_select_prep | rw.c | declared in param |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_iov_buffer_select_prep | rw.c | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | __io_import_rw_buffer | rw.c | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_meta_restore | rw.c | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_prep_rw_pi | rw.c | declared in param |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | __io_prep_rw | rw.c | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_init_rw_fixed | rw.c | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_rw_import_reg_vec | rw.c | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_rw_prep_reg_vec | rw.c | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_read_mshot_prep | rw.c | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_read_mshot_prep | rw.h | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_kiocb_update_pos | rw.c | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_rw_should_reissue | rw.c | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_req_end_write | rw.c | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_req_io_end | rw.c | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_req_rw_complete | rw.c | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_req_rw_complete | rw.h | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_complete_rw | rw.c | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_complete_rw_iopoll | rw.c | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_rw_done | rw.c | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | kiocb_done | rw.c | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_kiocb_ppos | rw.c | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | loop_rw_iter | rw.c | declared in param |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_async_buf_func | rw.c | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_rw_should_retry | rw.c | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_iter_do_read | rw.c | declared in param |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_rw_init_file | rw.c | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | __io_read | rw.c | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_read_mshot | rw.c | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_read_mshot | rw.h | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_write | rw.c | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_write | rw.h | used in body |
| io_rw | rw.c | addr, flags, here, kiocb, len, member | io_uring_classic_poll | rw.c | used in body |
| io_async_rw | rw.h | bytes_done, clear, fast_iov, io, iter, iter_state, meta, meta_state, struct, union, vec, with, wpq | io_ring_ctx_alloc | io_uring.c | used in body |
| io_async_rw | rw.h | bytes_done, clear, fast_iov, io, iter, iter_state, meta, meta_state, struct, union, vec, with, wpq | io_eopnotsupp_prep | opdef.c | used in body |
| io_async_rw | rw.h | bytes_done, clear, fast_iov, io, iter, iter_state, meta, meta_state, struct, union, vec, with, wpq | io_iov_buffer_select_prep | rw.c | used in body |
| io_async_rw | rw.h | bytes_done, clear, fast_iov, io, iter, iter_state, meta, meta_state, struct, union, vec, with, wpq | io_import_vec | rw.c | declared in param, used in body |
| io_async_rw | rw.h | bytes_done, clear, fast_iov, io, iter, iter_state, meta, meta_state, struct, union, vec, with, wpq | __io_import_rw_buffer | rw.c | declared in param, used in body |
| io_async_rw | rw.h | bytes_done, clear, fast_iov, io, iter, iter_state, meta, meta_state, struct, union, vec, with, wpq | io_import_rw_buffer | rw.c | declared in param |
| io_async_rw | rw.h | bytes_done, clear, fast_iov, io, iter, iter_state, meta, meta_state, struct, union, vec, with, wpq | io_rw_recycle | rw.c | used in body |
| io_async_rw | rw.h | bytes_done, clear, fast_iov, io, iter, iter_state, meta, meta_state, struct, union, vec, with, wpq | io_rw_alloc_async | rw.c | used in body |
| io_async_rw | rw.h | bytes_done, clear, fast_iov, io, iter, iter_state, meta, meta_state, struct, union, vec, with, wpq | io_meta_save_state | rw.c | declared in param, used in body |
| io_async_rw | rw.h | bytes_done, clear, fast_iov, io, iter, iter_state, meta, meta_state, struct, union, vec, with, wpq | io_meta_restore | rw.c | declared in param |
| io_async_rw | rw.h | bytes_done, clear, fast_iov, io, iter, iter_state, meta, meta_state, struct, union, vec, with, wpq | io_prep_rw_pi | rw.c | used in body |
| io_async_rw | rw.h | bytes_done, clear, fast_iov, io, iter, iter_state, meta, meta_state, struct, union, vec, with, wpq | io_init_rw_fixed | rw.c | used in body |
| io_async_rw | rw.h | bytes_done, clear, fast_iov, io, iter, iter_state, meta, meta_state, struct, union, vec, with, wpq | io_prep_write_fixed | rw.c | used in body |
| io_async_rw | rw.h | bytes_done, clear, fast_iov, io, iter, iter_state, meta, meta_state, struct, union, vec, with, wpq | io_prep_write_fixed | rw.h | used in body |
| io_async_rw | rw.h | bytes_done, clear, fast_iov, io, iter, iter_state, meta, meta_state, struct, union, vec, with, wpq | io_rw_import_reg_vec | rw.c | declared in param |
| io_async_rw | rw.h | bytes_done, clear, fast_iov, io, iter, iter_state, meta, meta_state, struct, union, vec, with, wpq | io_rw_prep_reg_vec | rw.c | used in body |
| io_async_rw | rw.h | bytes_done, clear, fast_iov, io, iter, iter_state, meta, meta_state, struct, union, vec, with, wpq | io_rw_should_reissue | rw.c | used in body |
| io_async_rw | rw.h | bytes_done, clear, fast_iov, io, iter, iter_state, meta, meta_state, struct, union, vec, with, wpq | io_fixup_rw_res | rw.c | used in body |
| io_async_rw | rw.h | bytes_done, clear, fast_iov, io, iter, iter_state, meta, meta_state, struct, union, vec, with, wpq | io_rw_should_retry | rw.c | used in body |
| io_async_rw | rw.h | bytes_done, clear, fast_iov, io, iter, iter_state, meta, meta_state, struct, union, vec, with, wpq | io_rw_init_file | rw.c | used in body |
| io_async_rw | rw.h | bytes_done, clear, fast_iov, io, iter, iter_state, meta, meta_state, struct, union, vec, with, wpq | __io_read | rw.c | used in body |
| io_async_rw | rw.h | bytes_done, clear, fast_iov, io, iter, iter_state, meta, meta_state, struct, union, vec, with, wpq | io_write | rw.c | used in body |
| io_async_rw | rw.h | bytes_done, clear, fast_iov, io, iter, iter_state, meta, meta_state, struct, union, vec, with, wpq | io_write | rw.h | used in body |
| io_async_rw | rw.h | bytes_done, clear, fast_iov, io, iter, iter_state, meta, meta_state, struct, union, vec, with, wpq | io_rw_cache_free | rw.c | used in body |
| io_async_rw | rw.h | bytes_done, clear, fast_iov, io, iter, iter_state, meta, meta_state, struct, union, vec, with, wpq | io_rw_cache_free | rw.h | used in body |
| io_splice | splice.c | file_out, flags, len, off_in, off_out, rsrc_node, splice_fd_in | io_eopnotsupp_prep | opdef.c | used in body |
| io_splice | splice.c | file_out, flags, len, off_in, off_out, rsrc_node, splice_fd_in | __io_splice_prep | splice.c | used in body |
| io_splice | splice.c | file_out, flags, len, off_in, off_out, rsrc_node, splice_fd_in | io_splice_cleanup | splice.c | used in body |
| io_splice | splice.c | file_out, flags, len, off_in, off_out, rsrc_node, splice_fd_in | io_splice_cleanup | splice.h | used in body |
| io_splice | splice.c | file_out, flags, len, off_in, off_out, rsrc_node, splice_fd_in | io_splice_get_file | splice.c | used in body |
| io_splice | splice.c | file_out, flags, len, off_in, off_out, rsrc_node, splice_fd_in | io_tee | splice.c | used in body |
| io_splice | splice.c | file_out, flags, len, off_in, off_out, rsrc_node, splice_fd_in | io_tee | splice.h | used in body |
| io_splice | splice.c | file_out, flags, len, off_in, off_out, rsrc_node, splice_fd_in | io_splice_prep | splice.c | used in body |
| io_splice | splice.c | file_out, flags, len, off_in, off_out, rsrc_node, splice_fd_in | io_splice_prep | splice.h | used in body |
| io_splice | splice.c | file_out, flags, len, off_in, off_out, rsrc_node, splice_fd_in | io_splice | splice.c | used in body |
| io_splice | splice.c | file_out, flags, len, off_in, off_out, rsrc_node, splice_fd_in | io_splice | splice.h | used in body |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_uring_show_fdinfo | fdinfo.c | used in body |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_uring_show_fdinfo | fdinfo.h | used in body |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_ring_exit_work | io_uring.c | used in body |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_ring_exit_work | sqpoll.c | used in body |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | tctx_inflight | io_uring.c | used in body |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_uring_cancel_generic | io_uring.c | declared in param |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_uring_cancel_generic | io_uring.h | declared in param |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_uring_cancel_generic | sqpoll.c | declared in param |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_should_wake | io_uring.c | used in body |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_should_wake | io_uring.h | used in body |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_should_wake | napi.c | used in body |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_unregister_iowq_aff | register.c | used in body |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_sq_thread_stop | sqpoll.c | declared in param, used in body |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_sq_thread_stop | sqpoll.h | declared in param, used in body |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_put_sq_data | register.c | declared in param, used in body |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_put_sq_data | sqpoll.c | declared in param, used in body |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_put_sq_data | sqpoll.h | declared in param, used in body |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_sqd_update_thread_idle | sqpoll.c | declared in param |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_sq_thread_finish | io_uring.c | used in body |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_sq_thread_finish | sqpoll.c | used in body |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_sq_thread_finish | sqpoll.h | used in body |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_attach_sq_data | sqpoll.c | used in body |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_get_sq_data | sqpoll.c | used in body |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_sqd_events_pending | sqpoll.c | declared in param |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | __io_sq_thread | sqpoll.c | used in body |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_sqd_handle_event | sqpoll.c | declared in param |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_sq_tw_pending | sqpoll.c | used in body |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_sq_update_worktime | sqpoll.c | declared in param |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_sq_thread | sqpoll.c | used in body |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_sq_offload_create | io_uring.c | used in body |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_sq_offload_create | sqpoll.c | used in body |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_sq_offload_create | sqpoll.h | used in body |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_sqpoll_wq_cpu_affinity | register.c | used in body |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_sqpoll_wq_cpu_affinity | sqpoll.c | used in body |
| io_sq_data | sqpoll.h | ctx_list, exited, lock, park_pending, refs, sq_cpu, sq_thread_idle, sqd, state, task_pid, task_tgid, thread, wait, work_time | io_sqpoll_wq_cpu_affinity | sqpoll.h | used in body |
| io_statx | statx.c | buffer, dfd, file, filename, flags, mask | io_eopnotsupp_prep | opdef.c | used in body |
| io_statx | statx.c | buffer, dfd, file, filename, flags, mask | io_statx_prep | statx.c | used in body |
| io_statx | statx.c | buffer, dfd, file, filename, flags, mask | io_statx_prep | statx.h | used in body |
| io_statx | statx.c | buffer, dfd, file, filename, flags, mask | io_statx | statx.c | used in body |
| io_statx | statx.c | buffer, dfd, file, filename, flags, mask | io_statx | statx.h | used in body |
| io_statx | statx.c | buffer, dfd, file, filename, flags, mask | io_statx_cleanup | statx.c | used in body |
| io_statx | statx.c | buffer, dfd, file, filename, flags, mask | io_statx_cleanup | statx.h | used in body |
| io_sync | sync.c | file, flags, len, mode, off | io_sfr_prep | sync.c | used in body |
| io_sync | sync.c | file, flags, len, mode, off | io_sfr_prep | sync.h | used in body |
| io_sync | sync.c | file, flags, len, mode, off | io_sync_file_range | sync.c | used in body |
| io_sync | sync.c | file, flags, len, mode, off | io_sync_file_range | sync.h | used in body |
| io_sync | sync.c | file, flags, len, mode, off | io_fsync_prep | sync.c | used in body |
| io_sync | sync.c | file, flags, len, mode, off | io_fsync_prep | sync.h | used in body |
| io_sync | sync.c | file, flags, len, mode, off | io_fsync | sync.c | used in body |
| io_sync | sync.c | file, flags, len, mode, off | io_fsync | sync.h | used in body |
| io_sync | sync.c | file, flags, len, mode, off | io_fallocate_prep | sync.c | used in body |
| io_sync | sync.c | file, flags, len, mode, off | io_fallocate_prep | sync.h | used in body |
| io_sync | sync.c | file, flags, len, mode, off | io_fallocate | sync.c | used in body |
| io_sync | sync.c | file, flags, len, mode, off | io_fallocate | sync.h | used in body |
| io_tctx_node | tctx.h | ctx, ctx_node, task | __io_async_cancel | cancel.c | used in body |
| io_tctx_node | tctx.h | ctx, ctx_node, task | io_ring_exit_work | io_uring.c | used in body |
| io_tctx_node | tctx.h | ctx, ctx_node, task | io_ring_exit_work | sqpoll.c | used in body |
| io_tctx_node | tctx.h | ctx, ctx_node, task | io_uring_try_cancel_iowq | io_uring.c | used in body |
| io_tctx_node | tctx.h | ctx, ctx_node, task | io_uring_try_cancel_iowq | tctx.c | used in body |
| io_tctx_node | tctx.h | ctx, ctx_node, task | io_uring_cancel_generic | io_uring.c | used in body |
| io_tctx_node | tctx.h | ctx, ctx_node, task | io_uring_cancel_generic | io_uring.h | used in body |
| io_tctx_node | tctx.h | ctx, ctx_node, task | io_uring_cancel_generic | sqpoll.c | used in body |
| io_tctx_node | tctx.h | ctx, ctx_node, task | io_unregister_iowq_aff | register.c | used in body |
| io_tctx_node | tctx.h | ctx, ctx_node, task | __io_uring_free | io_uring.c | used in body |
| io_tctx_node | tctx.h | ctx, ctx_node, task | __io_uring_free | tctx.c | used in body |
| io_tctx_node | tctx.h | ctx, ctx_node, task | __io_uring_add_tctx_node | io_uring.c | used in body |
| io_tctx_node | tctx.h | ctx, ctx_node, task | __io_uring_add_tctx_node | tctx.c | used in body |
| io_tctx_node | tctx.h | ctx, ctx_node, task | __io_uring_add_tctx_node | tctx.h | used in body |
| io_tctx_node | tctx.h | ctx, ctx_node, task | io_uring_del_tctx_node | io_uring.c | used in body |
| io_tctx_node | tctx.h | ctx, ctx_node, task | io_uring_del_tctx_node | tctx.c | used in body |
| io_tctx_node | tctx.h | ctx, ctx_node, task | io_uring_del_tctx_node | tctx.h | used in body |
| io_tctx_node | tctx.h | ctx, ctx_node, task | io_uring_clean_tctx | io_uring.c | used in body |
| io_tctx_node | tctx.h | ctx, ctx_node, task | io_uring_clean_tctx | tctx.c | used in body |
| io_tctx_node | tctx.h | ctx, ctx_node, task | io_uring_clean_tctx | tctx.h | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | io_eopnotsupp_prep | opdef.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | io_is_timeout_noseq | timeout.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | io_put_req | timeout.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | io_timeout_finish | timeout.c | declared in param |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | io_timeout_complete | timeout.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | io_flush_killed_timeouts | timeout.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | io_flush_timeouts | io_uring.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | io_flush_timeouts | timeout.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | io_flush_timeouts | timeout.h | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | advise.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | alloc_cache.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | alloc_cache.h | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | cancel.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | cancel.h | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | epoll.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | eventfd.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | fdinfo.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | filetable.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | fs.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | futex.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | io-wq.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | io-wq.h | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | io_uring.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | io_uring.h | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | kbuf.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | kbuf.h | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | memmap.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | msg_ring.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | napi.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | napi.h | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | net.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | nop.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | notif.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | notif.h | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | opdef.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | openclose.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | poll.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | refs.h | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | register.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | rsrc.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | rsrc.h | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | rw.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | slist.h | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | splice.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | sqpoll.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | statx.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | sync.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | tctx.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | tctx.h | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | timeout.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | timeout.h | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | truncate.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | uring_cmd.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | waitid.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | xattr.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | if | zcrx.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | io_timeout_fn | timeout.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | io_req_task_link_timeout | timeout.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | io_link_timeout_fn | timeout.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | io_timeout_get_clock | timeout.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | __io_timeout_prep | timeout.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | io_link_timeout_prep | timeout.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | io_link_timeout_prep | timeout.h | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | io_timeout | timeout.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | io_timeout | timeout.h | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | io_queue_linked_timeout | io_uring.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | io_queue_linked_timeout | timeout.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | io_queue_linked_timeout | timeout.h | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | io_kill_timeouts | io_uring.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | io_kill_timeouts | timeout.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | io_kill_timeouts | timeout.h | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | io_disarm_linked_timeout | timeout.c | used in body |
| io_timeout | timeout.c | completions, file, head, link, list, off, only, prev, repeats, target_seq | io_disarm_linked_timeout | timeout.h | used in body |
| io_timeout_rem | timeout.c | addr, file, flags, ltimeout, ts, update | io_timeout_remove_prep | timeout.c | used in body |
| io_timeout_rem | timeout.c | addr, file, flags, ltimeout, ts, update | io_timeout_remove_prep | timeout.h | used in body |
| io_timeout_rem | timeout.c | addr, file, flags, ltimeout, ts, update | io_timeout_remove | timeout.c | used in body |
| io_timeout_rem | timeout.c | addr, file, flags, ltimeout, ts, update | io_timeout_remove | timeout.h | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | io_eopnotsupp_prep | opdef.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | io_is_timeout_noseq | timeout.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | io_put_req | timeout.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | io_timeout_finish | timeout.c | declared in param |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | io_timeout_complete | timeout.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | io_flush_killed_timeouts | timeout.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | advise.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | alloc_cache.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | alloc_cache.h | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | cancel.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | cancel.h | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | epoll.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | eventfd.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | fdinfo.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | filetable.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | fs.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | futex.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | io-wq.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | io-wq.h | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | io_uring.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | io_uring.h | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | kbuf.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | kbuf.h | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | memmap.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | msg_ring.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | napi.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | napi.h | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | net.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | nop.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | notif.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | notif.h | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | opdef.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | openclose.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | poll.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | refs.h | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | register.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | rsrc.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | rsrc.h | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | rw.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | slist.h | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | splice.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | sqpoll.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | statx.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | sync.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | tctx.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | tctx.h | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | timeout.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | timeout.h | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | truncate.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | uring_cmd.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | waitid.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | xattr.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | if | zcrx.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | io_timeout_fn | timeout.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | io_link_timeout_fn | timeout.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | io_timeout_get_clock | timeout.c | declared in param, used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | __io_timeout_prep | timeout.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | io_timeout | timeout.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | io_timeout | timeout.h | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | io_queue_linked_timeout | io_uring.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | io_queue_linked_timeout | timeout.c | used in body |
| io_timeout_data | timeout.h | flags, mode, req, timer, ts | io_queue_linked_timeout | timeout.h | used in body |
| io_ftrunc | truncate.c | file, len | io_ftruncate_prep | truncate.c | used in body |
| io_ftrunc | truncate.c | file, len | io_ftruncate_prep | truncate.h | used in body |
| io_ftrunc | truncate.c | file, len | io_ftruncate | truncate.c | used in body |
| io_ftrunc | truncate.c | file, len | io_ftruncate | truncate.h | used in body |
| io_async_cmd | uring_cmd.h | 2, data, vec | io_ring_ctx_alloc | io_uring.c | used in body |
| io_async_cmd | uring_cmd.h | 2, data, vec | io_eopnotsupp_prep | opdef.c | used in body |
| io_async_cmd | uring_cmd.h | 2, data, vec | io_cmd_cache_free | uring_cmd.c | used in body |
| io_async_cmd | uring_cmd.h | 2, data, vec | io_cmd_cache_free | uring_cmd.h | used in body |
| io_async_cmd | uring_cmd.h | 2, data, vec | io_req_uring_cleanup | uring_cmd.c | used in body |
| io_async_cmd | uring_cmd.h | 2, data, vec | io_uring_cmd_prep_setup | uring_cmd.c | used in body |
| io_async_cmd | uring_cmd.h | 2, data, vec | io_uring_cmd_import_fixed_vec | uring_cmd.c | used in body |
| io_async_cmd | uring_cmd.h | 2, data, vec | io_uring_cmd_import_fixed_vec | uring_cmd.h | used in body |
| io_waitid | waitid.c | file, head, info, infop, options, refs, upid, which | io_eopnotsupp_prep | opdef.c | used in body |
| io_waitid | waitid.c | file, head, info, infop, options, refs, upid, which | io_waitid_free | waitid.c | used in body |
| io_waitid | waitid.c | file, head, info, infop, options, refs, upid, which | io_waitid_compat_copy_si | waitid.c | declared in param |
| io_waitid | waitid.c | file, head, info, infop, options, refs, upid, which | io_waitid_copy_si | waitid.c | used in body |
| io_waitid | waitid.c | file, head, info, infop, options, refs, upid, which | io_waitid_complete | waitid.c | used in body |
| io_waitid | waitid.c | file, head, info, infop, options, refs, upid, which | __io_waitid_cancel | waitid.c | used in body |
| io_waitid | waitid.c | file, head, info, infop, options, refs, upid, which | io_waitid_drop_issue_ref | waitid.c | used in body |
| io_waitid | waitid.c | file, head, info, infop, options, refs, upid, which | io_waitid_cb | waitid.c | used in body |
| io_waitid | waitid.c | file, head, info, infop, options, refs, upid, which | io_waitid_wait | waitid.c | used in body |
| io_waitid | waitid.c | file, head, info, infop, options, refs, upid, which | io_waitid_prep | waitid.c | used in body |
| io_waitid | waitid.c | file, head, info, infop, options, refs, upid, which | io_waitid_prep | waitid.h | used in body |
| io_waitid | waitid.c | file, head, info, infop, options, refs, upid, which | io_waitid | waitid.c | used in body |
| io_waitid | waitid.c | file, head, info, infop, options, refs, upid, which | io_waitid | waitid.h | used in body |
| io_waitid_async | waitid.h | req, wo | io_eopnotsupp_prep | opdef.c | used in body |
| io_waitid_async | waitid.h | req, wo | io_waitid_free | waitid.c | used in body |
| io_waitid_async | waitid.h | req, wo | __io_waitid_cancel | waitid.c | used in body |
| io_waitid_async | waitid.h | req, wo | io_waitid_drop_issue_ref | waitid.c | used in body |
| io_waitid_async | waitid.h | req, wo | io_waitid_cb | waitid.c | used in body |
| io_waitid_async | waitid.h | req, wo | io_waitid_wait | waitid.c | used in body |
| io_waitid_async | waitid.h | req, wo | io_waitid_prep | waitid.c | used in body |
| io_waitid_async | waitid.h | req, wo | io_waitid_prep | waitid.h | used in body |
| io_waitid_async | waitid.h | req, wo | io_waitid | waitid.c | used in body |
| io_waitid_async | waitid.h | req, wo | io_waitid | waitid.h | used in body |
| io_xattr | xattr.c | ctx, file, filename | io_xattr_cleanup | xattr.c | used in body |
| io_xattr | xattr.c | ctx, file, filename | io_xattr_cleanup | xattr.h | used in body |
| io_xattr | xattr.c | ctx, file, filename | __io_getxattr_prep | xattr.c | used in body |
| io_xattr | xattr.c | ctx, file, filename | io_getxattr_prep | xattr.c | used in body |
| io_xattr | xattr.c | ctx, file, filename | io_getxattr_prep | xattr.h | used in body |
| io_xattr | xattr.c | ctx, file, filename | io_fgetxattr | xattr.c | used in body |
| io_xattr | xattr.c | ctx, file, filename | io_fgetxattr | xattr.h | used in body |
| io_xattr | xattr.c | ctx, file, filename | io_getxattr | xattr.c | used in body |
| io_xattr | xattr.c | ctx, file, filename | io_getxattr | xattr.h | used in body |
| io_xattr | xattr.c | ctx, file, filename | __io_setxattr_prep | xattr.c | used in body |
| io_xattr | xattr.c | ctx, file, filename | io_setxattr_prep | xattr.c | used in body |
| io_xattr | xattr.c | ctx, file, filename | io_setxattr_prep | xattr.h | used in body |
| io_xattr | xattr.c | ctx, file, filename | io_fsetxattr | xattr.c | used in body |
| io_xattr | xattr.c | ctx, file, filename | io_fsetxattr | xattr.h | used in body |
| io_xattr | xattr.c | ctx, file, filename | io_setxattr | xattr.c | used in body |
| io_xattr | xattr.c | ctx, file, filename | io_setxattr | xattr.h | used in body |
| io_zcrx_args | zcrx.c | ifq, nr_skbs, req, sock | io_zcrx_sync_for_device | zcrx.c | used in body |
| io_zcrx_args | zcrx.c | ifq, nr_skbs, req, sock | io_zcrx_recv_skb | zcrx.c | used in body |
| io_zcrx_args | zcrx.c | ifq, nr_skbs, req, sock | io_zcrx_tcp_recvmsg | zcrx.c | used in body |
| io_zcrx_area | zcrx.h | ____cacheline_aligned_in_smp, area_id, free_count, freelist, ifq, is_mapped, nia, pages, user_refs | __io_zcrx_unmap_area | zcrx.c | declared in param, used in body |
| io_zcrx_area | zcrx.h | ____cacheline_aligned_in_smp, area_id, free_count, freelist, ifq, is_mapped, nia, pages, user_refs | io_zcrx_unmap_area | zcrx.c | declared in param, used in body |
| io_zcrx_area | zcrx.h | ____cacheline_aligned_in_smp, area_id, free_count, freelist, ifq, is_mapped, nia, pages, user_refs | io_zcrx_map_area | zcrx.c | declared in param |
| io_zcrx_area | zcrx.h | ____cacheline_aligned_in_smp, area_id, free_count, freelist, ifq, is_mapped, nia, pages, user_refs | io_zcrx_sync_for_device | zcrx.c | used in body |
| io_zcrx_area | zcrx.h | ____cacheline_aligned_in_smp, area_id, free_count, freelist, ifq, is_mapped, nia, pages, user_refs | io_zcrx_iov_to_area | zcrx.c | used in body |
| io_zcrx_area | zcrx.h | ____cacheline_aligned_in_smp, area_id, free_count, freelist, ifq, is_mapped, nia, pages, user_refs | io_get_user_counter | zcrx.c | used in body |
| io_zcrx_area | zcrx.h | ____cacheline_aligned_in_smp, area_id, free_count, freelist, ifq, is_mapped, nia, pages, user_refs | io_zcrx_iov_page | zcrx.c | used in body |
| io_zcrx_area | zcrx.h | ____cacheline_aligned_in_smp, area_id, free_count, freelist, ifq, is_mapped, nia, pages, user_refs | io_free_rbuf_ring | zcrx.c | used in body |
| io_zcrx_area | zcrx.h | ____cacheline_aligned_in_smp, area_id, free_count, freelist, ifq, is_mapped, nia, pages, user_refs | io_zcrx_free_area | zcrx.c | declared in param, used in body |
| io_zcrx_area | zcrx.h | ____cacheline_aligned_in_smp, area_id, free_count, freelist, ifq, is_mapped, nia, pages, user_refs | io_zcrx_create_area | zcrx.c | declared in param, used in body |
| io_zcrx_area | zcrx.h | ____cacheline_aligned_in_smp, area_id, free_count, freelist, ifq, is_mapped, nia, pages, user_refs | io_unregister_zcrx_ifqs | io_uring.c | used in body |
| io_zcrx_area | zcrx.h | ____cacheline_aligned_in_smp, area_id, free_count, freelist, ifq, is_mapped, nia, pages, user_refs | io_unregister_zcrx_ifqs | zcrx.c | used in body |
| io_zcrx_area | zcrx.h | ____cacheline_aligned_in_smp, area_id, free_count, freelist, ifq, is_mapped, nia, pages, user_refs | io_unregister_zcrx_ifqs | zcrx.h | used in body |
| io_zcrx_area | zcrx.h | ____cacheline_aligned_in_smp, area_id, free_count, freelist, ifq, is_mapped, nia, pages, user_refs | __io_zcrx_get_free_niov | zcrx.c | declared in param |
| io_zcrx_area | zcrx.h | ____cacheline_aligned_in_smp, area_id, free_count, freelist, ifq, is_mapped, nia, pages, user_refs | io_zcrx_return_niov_freelist | zcrx.c | used in body |
| io_zcrx_area | zcrx.h | ____cacheline_aligned_in_smp, area_id, free_count, freelist, ifq, is_mapped, nia, pages, user_refs | io_zcrx_scrub | zcrx.c | used in body |
| io_zcrx_area | zcrx.h | ____cacheline_aligned_in_smp, area_id, free_count, freelist, ifq, is_mapped, nia, pages, user_refs | io_zcrx_ring_refill | zcrx.c | used in body |
| io_zcrx_area | zcrx.h | ____cacheline_aligned_in_smp, area_id, free_count, freelist, ifq, is_mapped, nia, pages, user_refs | io_zcrx_refill_slow | zcrx.c | used in body |
| io_zcrx_area | zcrx.h | ____cacheline_aligned_in_smp, area_id, free_count, freelist, ifq, is_mapped, nia, pages, user_refs | io_pp_zc_destroy | zcrx.c | used in body |
| io_zcrx_area | zcrx.h | ____cacheline_aligned_in_smp, area_id, free_count, freelist, ifq, is_mapped, nia, pages, user_refs | io_zcrx_queue_cqe | zcrx.c | used in body |
| io_zcrx_area | zcrx.h | ____cacheline_aligned_in_smp, area_id, free_count, freelist, ifq, is_mapped, nia, pages, user_refs | io_zcrx_alloc_fallback | zcrx.c | declared in param |
| io_zcrx_area | zcrx.h | ____cacheline_aligned_in_smp, area_id, free_count, freelist, ifq, is_mapped, nia, pages, user_refs | io_zcrx_copy_chunk | zcrx.c | used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | __io_zcrx_unmap_area | zcrx.c | declared in param, used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_zcrx_unmap_area | zcrx.c | declared in param, used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_zcrx_map_area | zcrx.c | declared in param |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_zcrx_sync_for_device | zcrx.c | used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_zcrx_iov_page | zcrx.c | used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_allocate_rbuf_ring | zcrx.c | declared in param, used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_free_rbuf_ring | zcrx.c | declared in param |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_zcrx_free_area | zcrx.c | used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_zcrx_create_area | zcrx.c | declared in param, used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_zcrx_ifq_alloc | zcrx.c | used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_zcrx_drop_netdev | zcrx.c | declared in param, used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_close_queue | zcrx.c | declared in param, used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_zcrx_ifq_free | zcrx.c | declared in param |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_register_zcrx_ifq | register.c | used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_register_zcrx_ifq | zcrx.c | used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_register_zcrx_ifq | zcrx.h | used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_unregister_zcrx_ifqs | io_uring.c | used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_unregister_zcrx_ifqs | zcrx.c | used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_unregister_zcrx_ifqs | zcrx.h | used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_zcrx_return_niov | zcrx.c | used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_zcrx_scrub | zcrx.c | declared in param |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_shutdown_zcrx_ifqs | io_uring.c | used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_shutdown_zcrx_ifqs | zcrx.c | used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_shutdown_zcrx_ifqs | zcrx.h | used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_zcrx_rqring_entries | zcrx.c | declared in param, used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_zcrx_get_rqe | zcrx.c | declared in param, used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_zcrx_ring_refill | zcrx.c | declared in param, used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_zcrx_refill_slow | zcrx.c | declared in param |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_pp_zc_alloc_netmems | zcrx.c | used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_pp_zc_init | zcrx.c | used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_pp_zc_destroy | zcrx.c | used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_pp_uninstall | zcrx.c | used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_zcrx_queue_cqe | zcrx.c | declared in param |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_zcrx_alloc_fallback | zcrx.c | used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_zcrx_copy_chunk | zcrx.c | declared in param, used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_zcrx_copy_frag | zcrx.c | declared in param, used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_zcrx_recv_frag | zcrx.c | declared in param |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_zcrx_recv_skb | zcrx.c | used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_zcrx_tcp_recvmsg | zcrx.c | declared in param, used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_zcrx_recv | net.c | declared in param |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_zcrx_recv | zcrx.c | declared in param |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_zcrx_recv | zcrx.h | declared in param |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_shutdown_zcrx_ifqs | io_uring.c | used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_shutdown_zcrx_ifqs | zcrx.c | used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_shutdown_zcrx_ifqs | zcrx.h | used in body |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_zcrx_recv | net.c | declared in param |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_zcrx_recv | zcrx.c | declared in param |
| io_zcrx_ifq | zcrx.h | area, cached_rq_head, ctx, dev, if_rxq, lock, netdev, netdev_tracker, rq_entries, rq_lock, rq_ring, rqes | io_zcrx_recv | zcrx.h | declared in param |
