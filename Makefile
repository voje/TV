VERSION=0.0.1
IMG=voje/budget-kinect:${VERSION}
CNT=budget_kinect

build-docker:
	docker build . -t ${IMG}

run-docker: build-docker
	-docker rm -f ${CNT}
	docker run -it -v $(PWD):/project --name ${CNT} ${IMG} /bin/bash
