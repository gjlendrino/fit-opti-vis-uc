all: 
	lttng-gen-tp 

clean:
	rm -f 

trace-init:
	-lttng-sessiond --daemonize
	lttng create live_test_session --live &&\
	lttng enable-channel --userspace trace-channel &&\
	lttng start

trace-stop:
	lttng stop &&\
	lttng destroy
