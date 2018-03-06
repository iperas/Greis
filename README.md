# GREIS

A library for manipulating Javad GNSS's proprietary format data

## Getting Started

The repository consists of a Generator that parses the reference manual and produces CPP-code and pre-generated CPP-code for GNSS Receiver External Interface Specification that reflects receiver's firmware version 3.4.1. Use cmake . && make.

### Prerequisites
To build the CPP code:
* C++11 compiler
* Boost (regex, system, thread)
* CMake

To build the Generator:
* Microsoft Visual Studio 2010 or later or Mono

## License

This project is licensed under the LGPLv3 License - see the [LICENSE](LICENSE) file for details

## Acknowledgments

* Javad GNSS for their comprehensive approach to documentation for their devices
