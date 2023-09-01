FROM ubuntu:latest AS builder
RUN apt-get update && apt-get install -y \
    cmake \
    g++ \
    && rm -rf /var/lib/apt/lists/*
COPY /dynamiclibrary /dynamiclibrary
COPY /clientdynamiclibrary /clientdynamiclibrary
COPY CMakeLists.txt /
WORKDIR /build
RUN cmake ..
RUN make
WORKDIR /build
RUN cmake ..
RUN make

FROM ubuntu:latest
RUN mkdir output
COPY --from=builder /build/libdynamiclibrary.so /usr/lib
COPY --from=builder /build/clientdynamiclibrary /output
WORKDIR /output
CMD ["./clientdynamiclibrary"]