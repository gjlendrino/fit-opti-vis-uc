#
# Makefile for grpc infraestructure
#
CXX = g++
CPPFLAGS += `pkg-config --cflags protobuf grpc`
CXXFLAGS += -std=c++11

PROTODIR = ../proto
SOURCEDIR= ../grpc
ifeq ($(OS),Windows_NT)
	PLUGINDIR= $(shell which grpc_cpp_plugin.exe)
	PROTO=$(shell which protoc.exe )
else
	PLUGINDIR= $(shell which grpc_cpp_plugin)
	PROTO=$(shell which protoc)
endif

PROTOFILES = $(wildcard $(PROTODIR)/*.proto)
SOURCES = $(patsubst $(PROTODIR)/%.proto,$(SOURCEDIR)/%.pb.cc,$(PROTOFILES))
SRCFILES= $(wildcard $(SOURCEDIR)/*.pb.cc)


all: $(SOURCES)


$(SOURCEDIR)/%.pb.cc: $(PROTODIR)/%.proto
	$(PROTO) -I$(PROTODIR) --cpp_out=$(SOURCEDIR) $<
	$(PROTO) -I$(PROTODIR) --grpc_out=$(SOURCEDIR) --plugin=protoc-gen-grpc=$(PLUGINDIR) $<

clean:
		rm -f ../grpc/*.pb.cc ../grpc/*.pb.h 