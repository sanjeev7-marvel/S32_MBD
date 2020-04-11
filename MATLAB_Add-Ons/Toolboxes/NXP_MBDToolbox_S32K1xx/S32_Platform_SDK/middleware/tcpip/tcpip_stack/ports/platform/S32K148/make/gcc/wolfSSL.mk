WOLFSSLDIR=$(call TO_NATIVE,$(WOLFSSL_DIR))
WOLFSSLFILES=$(WOLFSSLDIR)/wolfcrypt/src/hmac.c \
	$(WOLFSSLDIR)/wolfcrypt/src/hash.c \
	$(WOLFSSLDIR)/wolfcrypt/src/cpuid.c \
	$(WOLFSSLDIR)/wolfcrypt/src/random.c \
	$(WOLFSSLDIR)/wolfcrypt/src/sha256.c \
	$(WOLFSSLDIR)/wolfcrypt/src/rsa.c \
	$(WOLFSSLDIR)/wolfcrypt/src/aes.c \
	$(WOLFSSLDIR)/wolfcrypt/src/sha.c \
	$(WOLFSSLDIR)/wolfcrypt/src/logging.c \
	$(WOLFSSLDIR)/wolfcrypt/src/wc_encrypt.c \
	$(WOLFSSLDIR)/wolfcrypt/src/wc_port.c \
	$(WOLFSSLDIR)/wolfcrypt/src/error.c \
	$(WOLFSSLDIR)/wolfcrypt/src/signature.c \
	$(WOLFSSLDIR)/wolfcrypt/src/wolfmath.c \
	$(WOLFSSLDIR)/wolfcrypt/src/memory.c \
	$(WOLFSSLDIR)/wolfcrypt/src/dh.c \
	$(WOLFSSLDIR)/wolfcrypt/src/asn.c \
	$(WOLFSSLDIR)/wolfcrypt/src/coding.c \
	$(WOLFSSLDIR)/wolfcrypt/src/tfm.c \
	$(WOLFSSLDIR)/src/internal.c \
	$(WOLFSSLDIR)/src/io.c \
	$(WOLFSSLDIR)/src/keys.c \
	$(WOLFSSLDIR)/src/ssl.c \
	$(WOLFSSLDIR)/src/tls.c

%.o: $(WOLFSSLDIR)/wolfcrypt/src/%.c
	$(CC) $(CFLAGS) -c $(<:.o=.c)

%.o: $(WOLFSSLDIR)/src/%.c
	$(CC) $(CFLAGS) -c $(<:.o=.c)

