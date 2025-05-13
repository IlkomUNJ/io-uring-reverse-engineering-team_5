# Task 1: Information about io_uring source
List in this section source and headers of io_uring. For each of the C source/header, you must put description what's the prime responsibily of the source. Take notes, description of the source should be slightly technical like the example given. 

## Source
### advice.c
Memproses permintaan advice terkait manajemen cache file (fadvise) dan manajemen memori (madvise) melalui mekanisme io_uring, di mana io_fadvise menggunakan vfs_fadvise untuk memberikan saran pada cache file system (seperti pola akses data), sedangkan io_madvise menggunakan do_madvise untuk memberikan saran pada manajemen memori virtual (seperti pembebasan memori). Kedua operasi ini diproses secara asinkronus dengan pengecekan kondisi tertentu seperti REQ_F_FORCE_ASYNC dan hanya io_madvise yang dikendalikan oleh flag kompilasi CONFIG_ADVISE_SYSCALLS dan CONFIG_MMU. 

### alloc_cache.c
Mengelola alokasi dan dealokasi memori dalam cache menggunakan struktur io_alloc_cache, di mana fungsi io_alloc_cache_init menginisialisasi cache dengan mengalokasikan array pointer menggunakan kvmalloc_array dan mengatur parameter seperti jumlah maksimum elemen (max_cached), ukuran elemen (elem_size), dan byte inisialisasi (init_clear), sementara io_alloc_cache_free membebaskan semua entri dalam cache dengan memanggil fungsi free yang diberikan untuk setiap elemen sebelum membebaskan array cache itu sendiri dengan kvfree, dan io_cache_alloc_new mengalokasikan objek baru menggunakan kmalloc dan menginisialisasi memori dengan nol jika init_clear diatur.

### cancel.c
Menangani operasi pembatalan asinkron dalam modul io_uring Linux, di mana ia menyediakan fungsi untuk mencocokkan dan membatalkan permintaan I/O berdasarkan kriteria seperti file descriptor, opcode, atau user data, dengan menggunakan struktur io_cancel_data untuk menentukan parameter pembatalan dan melakukan pencarian baik secara lokal pada io_wq pekerja saat ini maupun secara global pada semua pekerja melalui mekanisme lock-protected tctx_list, sambil juga menangani kasus edge seperti pembatalan timeout, poll, waitid, dan futex melalui fallback ke fungsi spesifik masing-masing.

### epoll.c
Mengimplementasikan fungsi epoll dalam io_uring, yang memungkinkan operasi epoll_ctl dan epoll_wait dijalankan secara asinkron melalui io_uring. Kode ini mendefinisikan dua struktur utama, io_epoll untuk operasi epoll_ctl (mengontrol file descriptor yang dimonitor) dan io_epoll_wait untuk operasi epoll_wait (menunggu event), serta menyediakan fungsi persiapan (*_prep) dan eksekusi untuk masing-masing operasi. Fungsi io_epoll_ctl memproses permintaan epoll_ctl dengan dukungan mode non-blocking, sementara io_epoll_wait mengirimkan event yang terjadi ke user space melalui mekanisme io_uring, dengan penanganan error dan hasil yang sesuai.

### eventfd.c
Mengelola integrasi antara eventfd dan io_uring, di mana fungsionalitas utamanya adalah memungkinkan notifikasi asinkron melalui eventfd ketika operasi I/O di io_uring selesai. Struktur io_ev_fd menyimpan konteks eventfd (cq_ev_fd) dan informasi terkait seperti status async (eventfd_async), referensi (refs), serta sinkronisasi menggunakan mekanisme RCU dan spinlock. Fungsi seperti io_eventfd_signal dan io_eventfd_flush_signal digunakan untuk memicu notifikasi eventfd ketika ada penyelesaian operasi I/O, sementara io_eventfd_register dan io_eventfd_unregister mengatur pendaftaran dan pelepasan eventfd dari konteks io_uring, dengan penanganan yang aman terhadap race condition menggunakan RCU dan lock.

### fdinfo.c
Menampilkan informasi file descriptor (fdinfo) terkait io_uring, sebuah antarmuka asinkron I/O di Linux, dengan mengekspos detail seperti status submission queue (SQ) dan completion queue (CQ), termasuk head/tail, mask, dan entri individual, serta informasi tambahan seperti SQ polling thread, file pengguna, buffer, dan kredensial, dimana beberapa bagian kode hanya aktif jika macro konfigurasi tertentu (seperti CONFIG_PROC_FS atau CONFIG_NET_RX_BUSY_POLL) diaktifkan selama kompilasi.

### filetable.c
Mengelola alokasi dan dealokasi file descriptor tetap (fixed file descriptors) dalam modul io_uring Linux, di mana fungsi utamanya mencakup pengelolaan bitmap untuk melacak slot file yang tersedia, instalasi file ke slot tetap, serta penanganan range alokasi file. Modul ini menggunakan struktur io_file_table untuk menyimpan bitmap dan data resource, dengan fungsi seperti io_file_bitmap_get untuk mencari slot kosong, io_install_fixed_file untuk mengaitkan file dengan slot tertentu, dan io_fixed_fd_remove untuk melepaskan resource. Selain itu, kode ini memastikan thread-safety dengan menggunakan lock (io_ring_submit_lock) selama operasi kritis dan menangani kasus error seperti overflow atau slot invalid.

### fs.c
Menangani operasi filesystem asinkron seperti rename, unlink, mkdir, symlink, dan link. Setiap operasi diimplementasikan melalui struktur khusus (seperti io_rename, io_unlink, dll.) yang menyimpan parameter operasi, fungsi preparasi (_prep) untuk memvalidasi dan mempersiapkan request, fungsi eksekusi asinkron (seperti io_renameat), serta fungsi cleanup untuk membebaskan resource. Kode ini memanfaatkan mekanisme io_uring untuk melakukan operasi filesystem secara efisien tanpa blocking, dengan penanganan error yang tepat dan manajemen memori yang aman melalui getname/putname.

### futex.c
Implementasi futex (fast userspace mutex) yang bertanggung jawab untuk menangani operasi-operasi sinkronisasi antar proses secara efisien di userspace. File ini mendefinisikan struktur data io_futex dan io_futex_data untuk menyimpan state futex, menyediakan fungsi-fungsi seperti io_futex_wait untuk menunggu suatu kondisi dan io_futex_wake untuk membangunkan thread yang menunggu, serta mengelola cache alokasi objek futex melalui io_futex_cache_init dan io_futex_cache_free. Implementasi ini mendukung baik operasi futex tunggal maupun multiple (vektor), dengan penanganan kasus-kasus seperti pembatalan operasi (io_futex_cancel) dan penyelesaian asinkron melalui task work.

### io-wq.c
Mengelola dan menjalankan pekerjaan asinkron secara efisien dengan memanfaatkan thread worker yang terbagi menjadi dua kategori: worker bound (terikat CPU tertentu) dan unbound (tidak terikat). Sistem ini menggunakan struktur data seperti hash table untuk mengelola pekerjaan, linked list untuk antrian pekerjaan, serta mekanisme wake-up dan sleep untuk mengoptimalkan penggunaan resource. Worker thread akan mengeksekusi pekerjaan dari antrian, dengan kemampuan untuk membatasi paralelisme pekerjaan yang di-hash ke nilai yang sama, serta mendukung pembatalan pekerjaan dan penyesuaian dinamik jumlah worker berdasarkan beban kerja.

### io_uring.c
Implementasi io_uring, mekanisme I/O asinkron berkinerja tinggi di Linux yang memungkinkan aplikasi melakukan operasi I/O dengan overhead rendah melalui pasangan ring buffer (submission dan completion queue) yang dibagi antara kernel dan user space, mendukung fitur seperti SQ polling, manajemen sumber daya, sinkronisasi memori, timeout, pembatalan operasi, dan integrasi dengan task_work kernel untuk eksekusi asinkron yang efisien.

### kbuf.c
Mengelola buffering data dalam operasi I/O asinkron, khususnya menyediakan mekanisme untuk menyediakan, memilih, dan mengembalikan buffer yang digunakan dalam operasi baca/tulis melalui io_uring. Kode ini menangani dua jenis buffer: legacy buffers (buffer tradisional yang dikelola via linked list) dan buffer rings (struktur berbentuk ring buffer yang lebih efisien). Fungsi utamanya meliputi alokasi/dealokasi buffer (io_provide_buffers, io_remove_buffers), seleksi buffer saat operasi I/O (io_buffer_select), serta manajemen metadata buffer seperti registrasi grup buffer (io_register_pbuf_ring) dan tracking status buffer. Implementasi ini memanfaatkan locking (uring_lock, mmap_lock) dan struktur data seperti XArray untuk mengelola buffer secara thread-safe, serta optimasi seperti commit inkremental untuk mengurangi overhead.

### memmap.c
Mengelola memori yang dipetakan (memory-mapped regions) dalam modul io_uring Linux, dengan fungsi utama seperti mengalokasikan halaman memori (baik dari kernel maupun user space), mem-pin halaman user space, memetakan region ke alamat virtual kernel melalui vmap, serta menangani operasi mmap untuk mengakses region tersebut dari user space. Kode ini menangani berbagai jenis region seperti ring buffers SQ/CQ, parameter, dan buffer pools, dengan mekanisme validasi dan proteksi yang ketat termasuk pengecekan overflow, pengelolaan referensi halaman, serta sinkronisasi menggunakan mmap_lock untuk keamanan multi-threading.

### msg_ring.c
Memungkinkan komunikasi dan pertukaran data antar-context io_uring melalui operasi IORING_MSG_DATA untuk mengirim data dan IORING_MSG_SEND_FD untuk mengirim file descriptor, dengan penanganan sinkronisasi yang melibatkan penguncian context target (io_lock_external_ctx), alokasi request (io_msg_get_kiocb), serta mekanisme task work (io_msg_tw_complete) untuk operasi asinkron, termasuk validasi flags dan pengecekan kondisi seperti IORING_SETUP_R_DISABLED atau konteks IOPOLL.

### napi.c
Mengimplementasikan fungsionalitas NAPI (New API) busy polling dalam io_uring, yang memungkinkan polling efisien untuk paket jaringan dengan mengurangi overhead interupsi. Modul ini menyediakan manajemen entri NAPI melalui hash table dan linked list, dengan dua mode pelacakan (static dan dynamic), di mana mode static mempertahankan entri secara permanen sementara mode dynamic membersihkan entri yang kadaluarsa setelah timeout. Fungsi utama termasuk menambah/menghapus ID NAPI, menjalankan busy loop polling dengan timeout yang dapat dikonfigurasi, serta handle registrasi/unregistrasi NAPI melalui syscall io_uring, dengan dukungan untuk preferensi busy polling dan penyesuaian parameter waktu polling.

### net.c
Implementasi operasi jaringan asinkron dalam modul io_uring yang menangani berbagai operasi socket seperti send, recv, accept, connect, bind, dan listen dengan dukungan zero-copy, multishot, dan fitur canggih lainnya. Fungsi utamanya adalah menyediakan antarmuka berkinerja tinggi untuk operasi I/O jaringan dengan meminimalkan overhead sistem dan memungkinkan penanganan permintaan secara paralel melalui mekanisme completion queue dan submission queue yang efisien. Kode ini melibatkan manajemen memori kompleks, optimasi penggunaan buffer, dan integrasi dengan subsistem socket kernel, sambil mendukung fitur seperti fixed buffers, polling, dan notifikasi.

### nop.c
Mengimplementasikan operasi NOP (no operation) dalam io_uring pada kernel Linux yang secara teknis memungkinkan pengguna untuk mengirim permintaan dummy melalui io_uring tanpa melakukan I/O nyata, namun tetap menguji jalur eksekusi dan parameter tertentu. Struktur io_nop menyimpan parameter seperti file descriptor, flags, dan hasil simulasi, sedangkan fungsi io_nop_prep mempersiapkan permintaan dengan membaca nilai-nilai dari submission queue entry (SQE) dan mengevaluasi flag tertentu untuk memutuskan apakah akan menyuntikkan hasil, menggunakan file tetap, atau buffer tetap. Fungsi io_nop kemudian menangani eksekusi permintaan NOP tersebut, mengelola pengambilan file dan buffer sesuai flag yang disetel, dan menetapkan hasil ke permintaan, dengan menangani kesalahan jika parameter tidak valid.

### notif.c
Menangani alur kerja zero-copy notification dalam konteks io_uring melalui struktur io_notif_data, yang berfungsi mengelola buffer pengguna (ubuf_info) dan menyinkronkan penyelesaian tugas-tugas asinkron saat data dikirim melalui jaringan. Struktur dan fungsi yang disediakan memungkinkan penggabungan beberapa notifikasi dalam satu task work dan memastikan manajemen memori serta pelaporan status transfer data seperti apakah zero-copy berhasil digunakan atau tidak. Mekanisme ini terintegrasi dengan sk_buff dan menggunakan callback yang terdaftar di ubuf_info_ops untuk menyelesaikan notifikasi, dengan perlakuan khusus terhadap referensi dan urutan task yang dieksekusi saat buffer telah tidak digunakan lagi.

### opdef.c
Bertugas sebagai tabel pemetaan opcode io_uring ke handler-nya masing-masing, dengan setiap entri dalam array io_issue_defs[] mendeskripsikan atribut teknis spesifik yang dibutuhkan seperti kebutuhan file, dukungan iopoll, penanganan prep dan issue function, serta alokasi struktur asinkron jika diperlukan; tabel ini memungkinkan kernel Linux untuk mengeksekusi berbagai operasi asynchronous secara efisien dan fleksibel, di mana masing-masing entri seperti IORING_OP_READV, IORING_OP_WRITEV, atau IORING_OP_TIMEOUT dipetakan langsung ke fungsi-fungsi penangan spesifik seperti io_read, io_write, atau io_timeout, sehingga mendukung performa tinggi dan kemampuan konfigurasi modular dalam sistem IO modern.

### openclose.c
Menangani operasi pembukaan dan penutupan file melalui antarmuka io_uring, dengan struktur utama seperti io_open, io_close, dan io_fixed_install yang merepresentasikan konteks masing-masing operasi. Fungsi-fungsi seperti io_openat, io_close, dan io_install_fixed_fd mengatur logika spesifik termasuk alokasi file descriptor, penanganan flag seperti O_CLOEXEC, serta sinkronisasi dan validasi yang ketat terhadap parameter dari submission queue entries (SQE). Penanganan asinkron, validasi kredensial, dan manajemen sumber daya (seperti fixed file slots) dilakukan secara hati-hati untuk memastikan integritas sistem dan kompatibilitas dengan model non-blok io_uring.

### poll.c
Mengelola polling dalam konteks operasi I/O asinkron menggunakan io_uring di kernel Linux. Kode ini bertanggung jawab untuk memeriksa dan menangani peristiwa polling, mengelola referensi objek terkait polling, dan memastikan bahwa proses polling dapat berjalan dengan benar melalui berbagai mekanisme, termasuk penanganan penghapusan entri, pengelolaan antrian tunggu, serta eksekusi tugas terkait polling. Selain itu, kode ini juga mengelola pengaturan status polling, baik itu untuk polling tunggal atau ganda, serta menangani pengelolaan kepemilikan sumber daya untuk memastikan tidak terjadi kondisi balapan.

### register.c
Mengelola pendaftaran dan pengaturan berbagai aspek dari io_uring, sebuah antarmuka sistem yang memungkinkan aplikasi untuk melakukan operasi I/O secara efisien menggunakan pemrograman berbasis antrian. Beberapa fungsi utama dalam kode ini meliputi registrasi dan pembatalan pendaftaran untuk berbagai jenis operasi, seperti pendaftaran untuk kepribadian tertentu (io_register_personality), pengaturan batasan operasi (io_register_restrictions), dan pengelolaan ukuran antrian serta sumber daya terkait (io_register_resize_rings). Kode ini juga menangani pengaturan afinitas CPU untuk pengolahan antrian I/O (io_register_iowq_aff). Secara keseluruhan, kode ini mengatur dan mengoptimalkan bagaimana operasi I/O dilakukan melalui io_uring, termasuk pengaturan sumber daya memori, pengendalian antrian, dan pengelolaan tugas dengan cara yang efisien.

### rsrc.c
Mengelola dan memperbarui sumber daya dalam konteks io_uring, yang merupakan antarmuka I/O asinkron di Linux. Kode ini menangani pendaftaran dan pembaruan file, buffer, dan sumber daya lainnya dalam sistem I/O, termasuk alokasi dan pembebasan memori yang terkait. Fungsi-fungsi yang ada, seperti io_account_mem dan io_buffer_validate, memastikan bahwa memori dan sumber daya I/O dikelola dengan benar, mencegah over-penyalahgunaan dan memastikan bahwa alokasi memori dilakukan sesuai dengan batasan yang ada. Selain itu, ada juga pengelolaan struktur data untuk buffer dan file, serta proses validasi dan penghitungan yang terkait dengan memori yang teralokasi, sehingga sistem tetap efisien dan aman dalam menangani operasi I/O.

### rw.c
Mengelola operasi baca/tulis (read/write) dengan menggunakan io_uring untuk melakukan input/output asinkron. Kode ini mengatur bagaimana buffer data disiapkan dan diimpor untuk operasi baca/tulis, serta bagaimana menyelesaikan operasi tersebut setelah selesai. Struktur data io_rw digunakan untuk menyimpan informasi terkait operasi I/O, seperti alamat buffer dan panjang data. Fungsi-fungsi seperti io_complete_rw dan io_req_rw_cleanup bertanggung jawab untuk menyelesaikan dan membersihkan sumber daya setelah operasi I/O selesai. Selain itu, kode ini juga mendukung pengolahan I/O dengan berbagai jenis buffer, termasuk buffer yang dipilih pengguna atau yang telah ditentukan sebelumnya.

### splice.c
Menangani operasi splice dan tee dalam io_uring yang memungkinkan transfer data antara dua file atau buffer tanpa melalui buffer pengguna. Fungsi io_splice dan io_tee bertanggung jawab untuk mempersiapkan, menjalankan, dan membersihkan operasi splice dan tee yang dilakukan dengan menggunakan file descriptor, yang dapat terhubung ke sumber data melalui io_splice_get_file. Struktur io_splice menyimpan informasi penting terkait file input dan output, offset, panjang data, dan flag, serta memastikan bahwa operasi tersebut dieksekusi secara asinkron dengan penanganan kegagalan yang sesuai. Fungsi-fungsi pendukung, seperti __io_splice_prep, memastikan validitas parameter yang diterima sebelum melanjutkan eksekusi operasi tersebut.

### sqpoll.c
Mengelola polling sisi pengajuan pada antrian pengajuan (SQ) dalam io_uring, yang memungkinkan aplikasi untuk mengelola operasi I/O secara efisien. Kode ini mencakup logika untuk mengelola thread yang bertanggung jawab atas polling dan pengajuan permintaan I/O, mengatur thread untuk berhenti atau diparkir, serta menangani keadaan di mana thread perlu di-unpark atau diberhentikan. Selain itu, kode ini juga mencakup pengelolaan sumber daya terkait dengan data yang terkait dengan polling, seperti pengaturan afinitas CPU, penanganan sinyal, dan pembaruan waktu kerja. Fungsi-fungsi tersebut bekerja bersama untuk mengoptimalkan pengelolaan beban kerja I/O dengan membagi tugas-tugas ini di antara beberapa thread atau CPU secara efisien.

### statx.c
Menangani operasi statx dalam konteks I/O asinkron menggunakan io_uring. Fungsi io_statx_prep mempersiapkan permintaan dengan mengambil informasi dari struktur io_uring_sqe, seperti file descriptor, path, dan buffer untuk hasil statx. Kemudian, fungsi io_statx melakukan operasi statx nyata melalui do_statx, yang mengambil metadata file berdasarkan parameter yang diberikan. Fungsi io_statx_cleanup bertanggung jawab untuk membersihkan sumber daya, seperti melepaskan nama file yang diambil. Kode ini memanfaatkan fitur io_uring untuk meningkatkan efisiensi I/O asinkron pada sistem Linux.

### sync.c
Menangani operasi sinkronisasi file dan alokasi ruang file secara asinkron menggunakan API io_uring di Linux. Kode ini melibatkan beberapa fungsi seperti io_sfr_prep untuk mempersiapkan parameter operasi sinkronisasi, io_sync_file_range dan io_fsync untuk melakukan sinkronisasi data atau metadata file ke disk, serta io_fallocate untuk mengalokasikan ruang kosong pada file. Semua operasi ini dilakukan dalam konteks pemrograman asinkron dengan memastikan bahwa beberapa operasi blok, seperti sinkronisasi dan alokasi file, dieksekusi dengan benar dalam konteks yang memerlukan pemblokiran (blocking context), sementara operasi lainnya dapat dilakukan secara non-blocking.

### tctx.c
Menangani pendaftaran dan pengelolaan sumber daya io_uring. Fungsi utama yang terlibat meliputi alokasi dan pengelolaan konteks tugas (task_context), pengaturan antrian kerja I/O, serta pendaftaran dan penghapusan file descriptor (fd) dalam konteks ini. Fungsi seperti io_ringfd_register dan io_ringfd_unregister mengelola pendaftaran dan penghapusan file descriptor yang terdaftar pada ring I/O, sementara fungsi io_uring_alloc_task_context bertanggung jawab untuk mengalokasikan dan menginisialisasi konteks tugas yang terkait dengan setiap proses. Selain itu, terdapat pengelolaan memori yang hati-hati menggunakan mutex untuk menghindari kondisi balapan, serta penanganan kesalahan alokasi memori dengan cara yang aman.

### timeout.c
Menangani mekanisme timeout dalam konteks I/O pada sistem yang menggunakan io_uring. Struktur dan fungsi dalam kode ini mengelola waktu tunggu (timeout) yang terkait dengan permintaan I/O, memungkinkan untuk penjadwalan dan pembatalan timeout, serta pembaruan atau penghapusan timeout yang sudah ada. Fungsi utama seperti io_timeout_fn dan io_timeout_complete berfokus pada pemrosesan dan penyelesaian timeout, sementara io_flush_timeouts memastikan bahwa timeout yang sudah tidak berlaku lagi dihapus atau diselesaikan dengan benar. Selain itu, kode ini juga menangani pembaruan atau pembatalan timeout yang terkait dengan tugas I/O yang lebih kompleks, seperti timeout berulang atau terkait dengan linked task.

### truncate.c
Mengelola operasi pemotongan ukuran file (truncate) dalam konteks io_uring. Struktur io_ftrunc menyimpan pointer ke file dan panjang baru file, yang akan digunakan dalam operasi ftruncate. Fungsi io_ftruncate_prep bertugas memvalidasi parameter dari io_uring_sqe, memastikan tidak ada flag atau field yang tidak sesuai, serta menyimpan offset sebagai panjang baru file. Fungsi io_ftruncate kemudian memanggil do_ftruncate untuk melakukan pemotongan file dan menyimpan hasilnya dalam request. Operasi ini dipaksa berjalan secara asinkron melalui flag REQ_F_FORCE_ASYNC, yang menandakan bahwa meskipun permintaan terlihat sederhana, ia tetap diproses melalui jalur asynchronous io_uring.

### uring_cmd.c
Sebagai pengelola utama alur eksekusi dan penanganan perintah io_uring_cmd di kernel Linux, menyediakan kerangka kerja bagi perangkat lunak tingkat pengguna untuk melakukan operasi I/O yang kompleks secara asynchronous dan efisien melalui antarmuka io_uring, secara teknis, ia menangani alokasi dan pembersihan data perintah asynchronous, pengaturan flags dan SQE, pendaftaran perintah sebagai cancelable, eksekusi deferred melalui task_work, serta integrasi dengan sistem keamanan dan subsistem jaringan seperti sockopt, dan semuanya dilakukan dengan pemisahan logika antara perintah biasa dan perintah dengan polling I/O, menjadikannya komponen penting dalam mendukung fleksibilitas dan performa tinggi pada subsistem io_uring.

### waitid.c
Mengimplementasikan dukungan asynchronous pada sistem waitid() dalam konteks io_uring, dengan tujuan memungkinkan proses menunggu perubahan status anak (seperti keluar atau berhenti) secara non-blocking. Modul ini mencakup struktur data io_waitid dan io_waitid_async yang menyimpan informasi proses yang ditunggu dan status sinyal, serta menyediakan mekanisme callback dan cancelation melalui antrian tugas (task_work) dan wait queue. Proses penanganan disesuaikan untuk konteks kompatibilitas (32-bit) dan menangani skenario seperti interupsi sinyal (-ERESTARTSYS) serta pembatalan operasi yang sedang aktif.

### xattr.c
Menangani operasi extended attributes (xattr) dengan menyediakan implementasi fungsi untuk mempersiapkan dan menjalankan pengambilan (getxattr) serta penyetelan atribut (setxattr) pada file descriptor langsung (fgetxattr/fsetxattr) maupun berdasarkan path (getxattr/setxattr), struktur io_xattr digunakan sebagai konteks yang menyimpan informasi terkait file, nama atribut, nilai atribut, dan flag, sedangkan proses pembersihan memori dialokasikan secara eksplisit melalui io_xattr_cleanup, dan eksekusi fungsi-fungsi utama dilakukan secara sinkron meskipun dipaksakan sebagai asynchronous melalui flag REQ_F_FORCE_ASYNC, dengan hasil akhir operasi disimpan menggunakan io_req_set_res.

### zcrx.c
Implementasi zero-copy receive queue (ZCRX) dalam io_uring yang memungkinkan aplikasi user space menerima data jaringan langsung ke buffer tanpa perlu penyalinan data tambahan antar ruang kernel dan user, secara teknis ia memetakan area memori pengguna, mem-pin halaman, dan memetakan/demapping buffer dengan DMA melalui dma_map_page_attrs dan dma_unmap_page_attrs, serta mengelola referensi buffer menggunakan struktur net_iov, dengan sinkronisasi dilakukan melalui spinlock dan atomic counter, di mana integrasi dengan jaringan dilakukan dengan membuka RX queue perangkat jaringan melalui memory provider ops khusus.

## Headers
### advice.h
int io_madvise_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_madvise(struct io_kiocb *req, unsigned int issue_flags);
int io_fadvise_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_fadvise(struct io_kiocb *req, unsigned int issue_flags);

### alloc_cache.h
void io_alloc_cache_free(struct io_alloc_cache *cache, void (*free)(const void *));
bool io_alloc_cache_init(struct io_alloc_cache *cache, unsigned max_nr, unsigned int size, unsigned int init_bytes);
void *io_cache_alloc_new(struct io_alloc_cache *cache, gfp_t gfp);
static inline bool io_alloc_cache_put(struct io_alloc_cache *cache, void *entry);
static inline void *io_alloc_cache_get(struct io_alloc_cache *cache);
static inline void *io_cache_alloc(struct io_alloc_cache *cache, gfp_t gfp);
static inline void io_cache_free(struct io_alloc_cache *cache, void *obj);

### cancel.h
int io_async_cancel_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_async_cancel(struct io_kiocb *req, unsigned int issue_flags);
int io_try_cancel(struct io_uring_task *tctx, struct io_cancel_data *cd, unsigned int issue_flags);
int io_sync_cancel(struct io_ring_ctx *ctx, void __user *arg);
bool io_cancel_req_match(struct io_kiocb *req, struct io_cancel_data *cd);
bool io_cancel_remove_all(struct io_ring_ctx *ctx, struct io_uring_task *tctx, struct hlist_head *list, bool cancel_all, bool (*cancel)(struct io_kiocb *));
int io_cancel_remove(struct io_ring_ctx *ctx, struct io_cancel_data *cd, unsigned int issue_flags, struct hlist_head *list, bool (*cancel)(struct io_kiocb *));

### epoll.h
int io_epoll_ctl_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_epoll_ctl(struct io_kiocb *req, unsigned int issue_flags);
int io_epoll_wait_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_epoll_wait(struct io_kiocb *req, unsigned int issue_flags);

### eventfd.h
int io_eventfd_register(struct io_ring_ctx *ctx, void __user *arg, unsigned int eventfd_async);
int io_eventfd_unregister(struct io_ring_ctx *ctx);
void io_eventfd_flush_signal(struct io_ring_ctx *ctx);
void io_eventfd_signal(struct io_ring_ctx *ctx);

### fdinfo.h
void io_uring_show_fdinfo(struct seq_file *m, struct file *f);

### filetable.h
bool io_alloc_file_tables(struct io_ring_ctx *ctx, struct io_file_table *table, unsigned nr_files);
void io_free_file_tables(struct io_ring_ctx *ctx, struct io_file_table *table);
int io_fixed_fd_install(struct io_kiocb *req, unsigned int issue_flags, struct file *file, unsigned int file_slot);
int __io_fixed_fd_install(struct io_ring_ctx *ctx, struct file *file, unsigned int file_slot);
int io_fixed_fd_remove(struct io_ring_ctx *ctx, unsigned int offset);
int io_register_file_alloc_range(struct io_ring_ctx *ctx, struct io_uring_file_index_range __user *arg);
io_req_flags_t io_file_get_flags(struct file *file);
static inline void io_file_bitmap_clear(struct io_file_table *table, int bit)
static inline void io_file_bitmap_set(struct io_file_table *table, int bit)
static inline unsigned int io_slot_flags(struct io_rsrc_node *node)
static inline struct file *io_slot_file(struct io_rsrc_node *node)
static inline void io_fixed_file_set(struct io_rsrc_node *node, struct file *file)
static inline void io_file_table_set_alloc_range(struct io_ring_ctx *ctx, unsigned off, unsigned len)

### fs.h
int io_renameat_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_renameat(struct io_kiocb *req, unsigned int issue_flags);
void io_renameat_cleanup(struct io_kiocb *req);
int io_unlinkat_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_unlinkat(struct io_kiocb *req, unsigned int issue_flags);
void io_unlinkat_cleanup(struct io_kiocb *req);
int io_mkdirat_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_mkdirat(struct io_kiocb *req, unsigned int issue_flags);
void io_mkdirat_cleanup(struct io_kiocb *req);
int io_symlinkat_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_symlinkat(struct io_kiocb *req, unsigned int issue_flags);
int io_linkat_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_linkat(struct io_kiocb *req, unsigned int issue_flags);
void io_link_cleanup(struct io_kiocb *req);

### futex.h
int io_futex_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_futexv_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_futex_wait(struct io_kiocb *req, unsigned int issue_flags);
int io_futexv_wait(struct io_kiocb *req, unsigned int issue_flags);
int io_futex_wake(struct io_kiocb *req, unsigned int issue_flags);
int io_futex_cancel(struct io_ring_ctx *ctx, struct io_cancel_data *cd, unsigned int issue_flags);
bool io_futex_remove_all(struct io_ring_ctx *ctx, struct io_uring_task *tctx, bool cancel_all);
bool io_futex_cache_init(struct io_ring_ctx *ctx);
void io_futex_cache_free(struct io_ring_ctx *ctx);
static inline int io_futex_cancel(struct io_ring_ctx *ctx, struct io_cancel_data *cd, unsigned int issue_flags)
static inline bool io_futex_remove_all(struct io_ring_ctx *ctx, struct io_uring_task *tctx, bool cancel_all)
static inline bool io_futex_cache_init(struct io_ring_ctx *ctx)
static inline void io_futex_cache_free(struct io_ring_ctx *ctx)

### io-wq.h
struct io_wq *io_wq_create(unsigned bounded, struct io_wq_data *data);
void io_wq_exit_start(struct io_wq *wq);
void io_wq_put_and_exit(struct io_wq *wq);
void io_wq_enqueue(struct io_wq *wq, struct io_wq_work *work);
void io_wq_hash_work(struct io_wq_work *work, void *val);
int io_wq_cpu_affinity(struct io_uring_task *tctx, cpumask_var_t mask);
int io_wq_max_workers(struct io_wq *wq, int *new_count);
bool io_wq_worker_stopped(void);
enum io_wq_cancel io_wq_cancel_cb(struct io_wq *wq, work_cancel_fn *cancel, void *data, bool cancel_all);
extern void io_wq_worker_sleeping(struct task_struct *); (dalam blok #if defined(CONFIG_IO_WQ))
extern void io_wq_worker_running(struct task_struct *); (dalam blok #if defined(CONFIG_IO_WQ))
typedef struct io_wq_work *(free_work_fn)(struct io_wq_work *);
typedef void (io_wq_work_fn)(struct io_wq_work *);
typedef bool (work_cancel_fn)(struct io_wq_work *, void *);

### io_uring.h
unsigned long rings_size(unsigned int flags, unsigned int sq_entries, unsigned int cq_entries, size_t *sq_offset);
int io_uring_fill_params(unsigned entries, struct io_uring_params *p);
bool io_cqe_cache_refill(struct io_ring_ctx *ctx, bool overflow);
int io_run_task_work_sig(struct io_ring_ctx *ctx);
void io_req_defer_failed(struct io_kiocb *req, s32 res);
bool io_post_aux_cqe(struct io_ring_ctx *ctx, u64 user_data, s32 res, u32 cflags);
void io_add_aux_cqe(struct io_ring_ctx *ctx, u64 user_data, s32 res, u32 cflags);
bool io_req_post_cqe(struct io_kiocb *req, s32 res, u32 cflags);
void __io_commit_cqring_flush(struct io_ring_ctx *ctx);
struct file *io_file_get_normal(struct io_kiocb *req, int fd);
struct file *io_file_get_fixed(struct io_kiocb *req, int fd, unsigned issue_flags);
void __io_req_task_work_add(struct io_kiocb *req, unsigned flags);
void io_req_task_work_add_remote(struct io_kiocb *req, unsigned flags);
void io_req_task_queue(struct io_kiocb *req);
void io_req_task_complete(struct io_kiocb *req, io_tw_token_t tw);
void io_req_task_queue_fail(struct io_kiocb *req, int ret);
void io_req_task_submit(struct io_kiocb *req, io_tw_token_t tw);
struct llist_node *io_handle_tw_list(struct llist_node *node, unsigned int *count, unsigned int max_entries);
struct llist_node *tctx_task_work_run(struct io_uring_task *tctx, unsigned int max_entries, unsigned int *count);
void tctx_task_work(struct callback_head *cb);
__cold void io_uring_cancel_generic(bool cancel_all, struct io_sq_data *sqd);
int io_uring_alloc_task_context(struct task_struct *task, struct io_ring_ctx *ctx);
int io_ring_add_registered_file(struct io_uring_task *tctx, struct file *file, int start, int end);
void io_req_queue_iowq(struct io_kiocb *req);
int io_poll_issue(struct io_kiocb *req, io_tw_token_t tw);
int io_submit_sqes(struct io_ring_ctx *ctx, unsigned int nr);
int io_do_iopoll(struct io_ring_ctx *ctx, bool force_nonspin);
void __io_submit_flush_completions(struct io_ring_ctx *ctx);
struct io_wq_work *io_wq_free_work(struct io_wq_work *work);
void io_wq_submit_work(struct io_wq_work *work);
void io_free_req(struct io_kiocb *req);
void io_queue_next(struct io_kiocb *req);
void io_task_refs_refill(struct io_uring_task *tctx);
bool __io_alloc_req_refill(struct io_ring_ctx *ctx);
bool io_match_task_safe(struct io_kiocb *head, struct io_uring_task *tctx, bool cancel_all);
void io_activate_pollwq(struct io_ring_ctx *ctx);

### kbuf.h
void __user *io_buffer_select(struct io_kiocb *req, size_t *len, unsigned int issue_flags);
int io_buffers_select(struct io_kiocb *req, struct buf_sel_arg *arg, unsigned int issue_flags);
int io_buffers_peek(struct io_kiocb *req, struct buf_sel_arg *arg);
void io_destroy_buffers(struct io_ring_ctx *ctx);
int io_remove_buffers_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_remove_buffers(struct io_kiocb *req, unsigned int issue_flags);
int io_provide_buffers_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_provide_buffers(struct io_kiocb *req, unsigned int issue_flags);
int io_register_pbuf_ring(struct io_ring_ctx *ctx, void __user *arg);
int io_unregister_pbuf_ring(struct io_ring_ctx *ctx, void __user *arg);
int io_register_pbuf_status(struct io_ring_ctx *ctx, void __user *arg);
bool io_kbuf_recycle_legacy(struct io_kiocb *req, unsigned issue_flags);
void io_kbuf_drop_legacy(struct io_kiocb *req);
unsigned int __io_put_kbufs(struct io_kiocb *req, int len, int nbufs);
bool io_kbuf_commit(struct io_kiocb *req, struct io_buffer_list *bl, int len, int nr);
struct io_mapped_region *io_pbuf_get_region(struct io_ring_ctx *ctx, unsigned int bgid);
Selain fungsi-fungsi di atas, terdapat juga beberapa fungsi inline yang didefinisikan dalam header ini:
static inline bool io_kbuf_recycle_ring(struct io_kiocb *req)
static inline bool io_do_buffer_select(struct io_kiocb *req)
static inline bool io_kbuf_recycle(struct io_kiocb *req, unsigned issue_flags)
static inline unsigned int io_put_kbuf(struct io_kiocb *req, int len, unsigned issue_flags)
static inline unsigned int io_put_kbufs(struct io_kiocb *req, int len, int nbufs, unsigned issue_flags)void __user *io_buffer_select(struct io_kiocb *req, size_t *len, unsigned int issue_flags);
int io_buffers_select(struct io_kiocb *req, struct buf_sel_arg *arg, unsigned int issue_flags);
int io_buffers_peek(struct io_kiocb *req, struct buf_sel_arg *arg);
void io_destroy_buffers(struct io_ring_ctx *ctx);
int io_remove_buffers_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_remove_buffers(struct io_kiocb *req, unsigned int issue_flags);
int io_provide_buffers_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_provide_buffers(struct io_kiocb *req, unsigned int issue_flags);
int io_register_pbuf_ring(struct io_ring_ctx *ctx, void __user *arg);
int io_unregister_pbuf_ring(struct io_ring_ctx *ctx, void __user *arg);
int io_register_pbuf_status(struct io_ring_ctx *ctx, void __user *arg);
bool io_kbuf_recycle_legacy(struct io_kiocb *req, unsigned issue_flags);
void io_kbuf_drop_legacy(struct io_kiocb *req);
unsigned int __io_put_kbufs(struct io_kiocb *req, int len, int nbufs);
bool io_kbuf_commit(struct io_kiocb *req, struct io_buffer_list *bl, int len, int nr);
struct io_mapped_region *io_pbuf_get_region(struct io_ring_ctx *ctx, unsigned int bgid);
Selain fungsi-fungsi di atas, terdapat juga beberapa fungsi inline yang didefinisikan dalam header ini:
static inline bool io_kbuf_recycle_ring(struct io_kiocb *req)
static inline bool io_do_buffer_select(struct io_kiocb *req)
static inline bool io_kbuf_recycle(struct io_kiocb *req, unsigned issue_flags)
static inline unsigned int io_put_kbuf(struct io_kiocb *req, int len, unsigned issue_flags)
static inline unsigned int io_put_kbufs(struct io_kiocb *req, int len, int nbufs, unsigned issue_flags)

### memmap.h
struct page **io_pin_pages(unsigned long ubuf, unsigned long len, int *npages);
unsigned int io_uring_nommu_mmap_capabilities(struct file *file);
unsigned long io_uring_get_unmapped_area(struct file *file, unsigned long addr, unsigned long len, unsigned long pgoff, unsigned long flags);
int io_uring_mmap(struct file *file, struct vm_area_struct *vma);
void io_free_region(struct io_ring_ctx *ctx, struct io_mapped_region *mr);
int io_create_region(struct io_ring_ctx *ctx, struct io_mapped_region *mr, struct io_uring_region_desc *reg, unsigned long mmap_offset);
int io_create_region_mmap_safe(struct io_ring_ctx *ctx, struct io_mapped_region *mr, struct io_uring_region_desc *reg, unsigned long mmap_offset);

### msg_ring.h
int io_uring_sync_msg_ring(struct io_uring_sqe *sqe);
int io_msg_ring_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_msg_ring(struct io_kiocb *req, unsigned int issue_flags);
void io_msg_ring_cleanup(struct io_kiocb *req);

### napi.h
void io_napi_init(struct io_ring_ctx *ctx);
void io_napi_free(struct io_ring_ctx *ctx);
int io_register_napi(struct io_ring_ctx *ctx, void __user *arg);
int io_unregister_napi(struct io_ring_ctx *ctx, void __user *arg);
int __io_napi_add_id(struct io_ring_ctx *ctx, unsigned int napi_id);
void __io_napi_busy_loop(struct io_ring_ctx *ctx, struct io_wait_queue *iowq);
int io_napi_sqpoll_busy_poll(struct io_ring_ctx *ctx);
static inline bool io_napi(struct io_ring_ctx *ctx)
static inline void io_napi_busy_loop(struct io_ring_ctx *ctx, struct io_wait_queue *iowq)
static inline void io_napi_add(struct io_kiocb *req)
static inline void io_napi_init(struct io_ring_ctx *ctx)
static inline void io_napi_free(struct io_ring_ctx *ctx)
static inline int io_register_napi(struct io_ring_ctx *ctx, void __user *arg)
static inline int io_unregister_napi(struct io_ring_ctx *ctx, void __user *arg)
static inline bool io_napi(struct io_ring_ctx *ctx)
static inline void io_napi_add(struct io_kiocb *req)
static inline void io_napi_busy_loop(struct io_ring_ctx *ctx, struct io_wait_queue *iowq)
static inline int io_napi_sqpoll_busy_poll(struct io_ring_ctx *ctx)

### net.h
int io_shutdown_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_shutdown(struct io_kiocb *req, unsigned int issue_flags);
void io_sendmsg_recvmsg_cleanup(struct io_kiocb *req);
int io_sendmsg_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_sendmsg(struct io_kiocb *req, unsigned int issue_flags);
int io_send(struct io_kiocb *req, unsigned int issue_flags);
int io_recvmsg_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_recvmsg(struct io_kiocb *req, unsigned int issue_flags);
int io_recv(struct io_kiocb *req, unsigned int issue_flags);
void io_sendrecv_fail(struct io_kiocb *req);
int io_accept_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_accept(struct io_kiocb *req, unsigned int issue_flags);
int io_socket_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_socket(struct io_kiocb *req, unsigned int issue_flags);
int io_connect_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_connect(struct io_kiocb *req, unsigned int issue_flags);
int io_send_zc(struct io_kiocb *req, unsigned int issue_flags);
int io_sendmsg_zc(struct io_kiocb *req, unsigned int issue_flags);
int io_send_zc_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
void io_send_zc_cleanup(struct io_kiocb *req);
int io_bind_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_bind(struct io_kiocb *req, unsigned int issue_flags);
int io_listen_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_listen(struct io_kiocb *req, unsigned int issue_flags);
void io_netmsg_cache_free(const void *entry);

### nop.h
int io_nop_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_nop(struct io_kiocb *req, unsigned int issue_flags);

### notif.h
struct io_kiocb *io_alloc_notif(struct io_ring_ctx *ctx);
void io_tx_ubuf_complete(struct sk_buff *skb, struct ubuf_info *uarg, bool success);

### opdef.h
int (*issue)(struct io_kiocb *, unsigned int);
int (*prep)(struct io_kiocb *, const struct io_uring_sqe *);
void (*cleanup)(struct io_kiocb *);
void (*fail)(struct io_kiocb *);
bool io_uring_op_supported(u8 opcode);
void io_uring_optable_init(void);

### openclose.h
int __io_close_fixed(struct io_ring_ctx *ctx, unsigned int issue_flags, unsigned int offset);
int io_openat_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_openat(struct io_kiocb *req, unsigned int issue_flags);
void io_open_cleanup(struct io_kiocb *req);
int io_openat2_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_openat2(struct io_kiocb *req, unsigned int issue_flags);
int io_close_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_close(struct io_kiocb *req, unsigned int issue_flags);
int io_install_fixed_fd_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_install_fixed_fd(struct io_kiocb *req, unsigned int issue_flags);

### poll.h
int io_poll_add_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_poll_add(struct io_kiocb *req, unsigned int issue_flags);
int io_poll_remove_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_poll_remove(struct io_kiocb *req, unsigned int issue_flags);
int io_poll_cancel(struct io_ring_ctx *ctx, struct io_cancel_data *cd, unsigned issue_flags);
int io_arm_poll_handler(struct io_kiocb *req, unsigned issue_flags);
bool io_poll_remove_all(struct io_ring_ctx *ctx, struct io_uring_task *tctx, bool cancel_all);
void io_poll_task_func(struct io_kiocb *req, io_tw_token_t tw);

### refs.h
static inline bool req_ref_inc_not_zero(struct io_kiocb *req)
static inline bool req_ref_put_and_test_atomic(struct io_kiocb *req)
static inline bool req_ref_put_and_test(struct io_kiocb *req)
static inline void req_ref_get(struct io_kiocb *req)
static inline void req_ref_put(struct io_kiocb *req)
static inline void __io_req_set_refcount(struct io_kiocb *req, int nr)
static inline void io_req_set_refcount(struct io_kiocb *req)

### register.h
int io_eventfd_unregister(struct io_ring_ctx *ctx);
int io_unregister_personality(struct io_ring_ctx *ctx, unsigned id);
struct file *io_uring_register_get_file(unsigned int fd, bool registered);

### rsrc.h
bool io_rsrc_cache_init(struct io_ring_ctx *ctx);
void io_rsrc_cache_free(struct io_ring_ctx *ctx);
struct io_rsrc_node *io_rsrc_node_alloc(struct io_ring_ctx *ctx, int type);
void io_free_rsrc_node(struct io_ring_ctx *ctx, struct io_rsrc_node *node);
void io_rsrc_data_free(struct io_ring_ctx *ctx, struct io_rsrc_data *data);
int io_rsrc_data_alloc(struct io_rsrc_data *data, unsigned nr);
struct io_rsrc_node *io_find_buf_node(struct io_kiocb *req, unsigned issue_flags);
int io_import_reg_buf(struct io_kiocb *req, struct iov_iter *iter, u64 buf_addr, size_t len, int ddir, unsigned issue_flags);
int io_import_reg_vec(int ddir, struct iov_iter *iter, struct io_kiocb *req, struct iou_vec *vec, unsigned nr_iovs, unsigned issue_flags);
int io_prep_reg_iovec(struct io_kiocb *req, struct iou_vec *iv, const struct iovec __user *uvec, size_t uvec_segs);
int io_register_clone_buffers(struct io_ring_ctx *ctx, void __user *arg);
int io_sqe_buffers_unregister(struct io_ring_ctx *ctx);
int io_sqe_buffers_register(struct io_ring_ctx *ctx, void __user *arg, unsigned int nr_args, u64 __user *tags);
int io_sqe_files_unregister(struct io_ring_ctx *ctx);
int io_sqe_files_register(struct io_ring_ctx *ctx, void __user *arg, unsigned nr_args, u64 __user *tags);
int io_register_files_update(struct io_ring_ctx *ctx, void __user *arg, unsigned nr_args);
int io_register_rsrc_update(struct io_ring_ctx *ctx, void __user *arg, unsigned size, unsigned type);
int io_register_rsrc(struct io_ring_ctx *ctx, void __user *arg, unsigned int size, unsigned int type);
int io_buffer_validate(struct iovec *iov);
bool io_check_coalesce_buffer(struct page **page_array, int nr_pages, struct io_imu_folio_data *data);
int io_files_update(struct io_kiocb *req, unsigned int issue_flags);
int io_files_update_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int __io_account_mem(struct user_struct *user, unsigned long nr_pages);
void io_vec_free(struct iou_vec *iv);
int io_vec_realloc(struct iou_vec *iv, unsigned nr_entries);
Inline Functions (which are also part of the specification):
static inline struct io_rsrc_node *io_rsrc_node_lookup(struct io_rsrc_data *data, int index);
static inline void io_put_rsrc_node(struct io_ring_ctx *ctx, struct io_rsrc_node *node);
static inline bool io_reset_rsrc_node(struct io_ring_ctx *ctx, struct io_rsrc_data *data, int index);
static inline void io_req_put_rsrc_nodes(struct io_kiocb *req);
static inline void io_req_assign_rsrc_node(struct io_rsrc_node **dst_node, struct io_rsrc_node *node);
static inline void io_req_assign_buf_node(struct io_kiocb *req, struct io_rsrc_node *node);
static inline void io_vec_reset_iovec(struct iou_vec *iv, struct iovec *iovec, unsigned nr);
static inline void io_alloc_cache_vec_kasan(struct iou_vec *iv);

### rw.h
int io_prep_read_fixed(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_prep_write_fixed(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_prep_readv_fixed(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_prep_writev_fixed(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_prep_readv(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_prep_writev(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_prep_read(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_prep_write(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_read(struct io_kiocb *req, unsigned int issue_flags);
int io_write(struct io_kiocb *req, unsigned int issue_flags);
int io_read_fixed(struct io_kiocb *req, unsigned int issue_flags);
int io_write_fixed(struct io_kiocb *req, unsigned int issue_flags);
void io_readv_writev_cleanup(struct io_kiocb *req);
void io_rw_fail(struct io_kiocb *req);
void io_req_rw_complete(struct io_kiocb *req, io_tw_token_t tw);
int io_read_mshot_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_read_mshot(struct io_kiocb *req, unsigned int issue_flags);
void io_rw_cache_free(const void *entry);

### slist.h
static inline void wq_list_add_after(struct io_wq_work_node *node, struct io_wq_work_node *pos, struct io_wq_work_list *list)
static inline void wq_list_add_tail(struct io_wq_work_node *node, struct io_wq_work_list *list)
static inline void wq_list_add_head(struct io_wq_work_node *node, struct io_wq_work_list *list)
static inline void wq_list_cut(struct io_wq_work_list *list, struct io_wq_work_node *last, struct io_wq_work_node *prev)
static inline void __wq_list_splice(struct io_wq_work_list *list, struct io_wq_work_node *to)
static inline bool wq_list_splice(struct io_wq_work_list *list, struct io_wq_work_node *to)
static inline void wq_stack_add_head(struct io_wq_work_node *node, struct io_wq_work_node *stack)
static inline void wq_list_del(struct io_wq_work_list *list, struct io_wq_work_node *node, struct io_wq_work_node *prev)
static inline struct io_wq_work_node *wq_stack_extract(struct io_wq_work_node *stack)
static inline struct io_wq_work *wq_next_work(struct io_wq_work *work)

### splice.h
int io_tee_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_tee(struct io_kiocb *req, unsigned int issue_flags);
void io_splice_cleanup(struct io_kiocb *req);
int io_splice_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_splice(struct io_kiocb *req, unsigned int issue_flags);

### sqpoll.h
int io_sq_offload_create(struct io_ring_ctx *ctx, struct io_uring_params *p);
void io_sq_thread_finish(struct io_ring_ctx *ctx);
void io_sq_thread_stop(struct io_sq_data *sqd);
void io_sq_thread_park(struct io_sq_data *sqd);
void io_sq_thread_unpark(struct io_sq_data *sqd);
void io_put_sq_data(struct io_sq_data *sqd);
void io_sqpoll_wait_sq(struct io_ring_ctx *ctx);
int io_sqpoll_wq_cpu_affinity(struct io_ring_ctx *ctx, cpumask_var_t mask);

### statx.h
int io_statx_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_statx(struct io_kiocb *req, unsigned int issue_flags);
void io_statx_cleanup(struct io_kiocb *req);

### sync.h
int io_sfr_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_sync_file_range(struct io_kiocb *req, unsigned int issue_flags);
int io_fsync_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_fsync(struct io_kiocb *req, unsigned int issue_flags);
int io_fallocate(struct io_kiocb *req, unsigned int issue_flags);
int io_fallocate_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

### tctx.h
int io_uring_alloc_task_context(struct task_struct *task, struct io_ring_ctx *ctx);
void io_uring_del_tctx_node(unsigned long index);
int __io_uring_add_tctx_node(struct io_ring_ctx *ctx);
int __io_uring_add_tctx_node_from_submit(struct io_ring_ctx *ctx);
void io_uring_clean_tctx(struct io_uring_task *tctx);
void io_uring_unreg_ringfd(void);
int io_ringfd_register(struct io_ring_ctx *ctx, void __user *__arg, unsigned nr_args);
int io_ringfd_unregister(struct io_ring_ctx *ctx, void __user *__arg, unsigned nr_args);
static inline int io_uring_add_tctx_node(struct io_ring_ctx *ctx);

### timeout.h
struct io_kiocb *__io_disarm_linked_timeout(struct io_kiocb *req, struct io_kiocb *link);
__cold void io_flush_timeouts(struct io_ring_ctx *ctx);
int io_timeout_cancel(struct io_ring_ctx *ctx, struct io_cancel_data *cd);
__cold bool io_kill_timeouts(struct io_ring_ctx *ctx, struct io_uring_task *tctx, bool cancel_all);
void io_queue_linked_timeout(struct io_kiocb *req);
void io_disarm_next(struct io_kiocb *req);
int io_timeout_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_link_timeout_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_timeout(struct io_kiocb *req, unsigned int issue_flags);
int io_timeout_remove_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_timeout_remove(struct io_kiocb *req, unsigned int issue_flags);

### truncate.h
int io_ftruncate_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_ftruncate(struct io_kiocb *req, unsigned int issue_flags);

### uring_cmd.h
int io_uring_cmd(struct io_kiocb *req, unsigned int issue_flags);
int io_uring_cmd_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
void io_uring_cmd_cleanup(struct io_kiocb *req);
bool io_uring_try_cancel_uring_cmd(struct io_ring_ctx *ctx, struct io_uring_task *tctx, bool cancel_all);
void io_cmd_cache_free(const void *entry);
int io_uring_cmd_import_fixed_vec(struct io_uring_cmd *ioucmd, const struct iovec __user *uvec, size_t uvec_segs, int ddir, struct iov_iter *iter, unsigned issue_flags);

### waitid.h
int io_waitid_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_waitid(struct io_kiocb *req, unsigned int issue_flags);
int io_waitid_cancel(struct io_ring_ctx *ctx, struct io_cancel_data *cd, unsigned int issue_flags);
bool io_waitid_remove_all(struct io_ring_ctx *ctx, struct io_uring_task *tctx, bool cancel_all);

### xattr.h
void io_xattr_cleanup(struct io_kiocb *req);
int io_fsetxattr_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_fsetxattr(struct io_kiocb *req, unsigned int issue_flags);
int io_setxattr_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_setxattr(struct io_kiocb *req, unsigned int issue_flags);
int io_fgetxattr_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_fgetxattr(struct io_kiocb *req, unsigned int issue_flags);
int io_getxattr_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_getxattr(struct io_kiocb *req, unsigned int issue_flags);

### zcrx.h
int io_register_zcrx_ifq(struct io_ring_ctx *ctx, struct io_uring_zcrx_ifq_reg __user *arg);
void io_unregister_zcrx_ifqs(struct io_ring_ctx *ctx);
void io_shutdown_zcrx_ifqs(struct io_ring_ctx *ctx);
int io_zcrx_recv(struct io_kiocb *req, struct io_zcrx_ifq *ifq, struct socket *sock, unsigned int flags, unsigned issue_flags, unsigned int *len);
static inline int io_register_zcrx_ifq(struct io_ring_ctx *ctx, struct io_uring_zcrx_ifq_reg __user *arg)
static inline void io_unregister_zcrx_ifqs(struct io_ring_ctx *ctx)
static inline void io_shutdown_zcrx_ifqs(struct io_ring_ctx *ctx)
static inline int io_zcrx_recv(struct io_kiocb *req, struct io_zcrx_ifq *ifq, struct socket *sock, unsigned int flags, unsigned issue_flags, unsigned int *len)
int io_recvzc(struct io_kiocb *req, unsigned int issue_flags);
int io_recvzc_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
