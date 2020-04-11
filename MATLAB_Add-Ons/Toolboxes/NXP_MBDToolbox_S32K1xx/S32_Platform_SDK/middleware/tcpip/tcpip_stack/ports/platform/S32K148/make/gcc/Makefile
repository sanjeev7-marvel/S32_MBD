# Copyright 2017 NXP
# All rights reserved.
#
# THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
# IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
# OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
# IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
# INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
# STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
# IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
# THE POSSIBILITY OF SUCH DAMAGE.
#
# This file is derived from lwIP contribution example with the following copyright:
#
# Copyright (c) 2001-2004 Swedish Institute of Computer Science.
# All rights reserved.


ifeq ($(OS),Windows_NT)
    CYGPATH=cygpath
    TO_NATIVE=$(shell $(CYGPATH) -m -i ${1})
    TO_UNIX=$(shell $(CYGPATH) -u -i ${1})
    TO_LOWER=$(shell echo ${1})
else
    TO_NATIVE=$(shell echo ${1})
    TO_UNIX=$(shell echo ${1})
    TO_LOWER=$(shell echo ${1} | tr A-Z a-z)
endif


include UserPaths.mk

all : test
.PHONY: all

include Common.mk

clean:
	rm *.o test.elf test.map .depend* *.cgraph *.su

depend dep: .depend

include .depend

.depend: $(ALL_SOURCES)
	$(CCDEP) $(CFLAGS) -MM $^ > .depend || rm .depend

test: .depend $(ALL_OBJECTS)
	$(LD) $(LDFLAGS) -Xlinker -Map=test.map -Xlinker -o -Xlinker test.elf -Wl,--start-group $(ALL_OBJECTS) -Wl,--end-group
