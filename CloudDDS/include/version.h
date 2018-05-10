//
// Version.h
//
// Version information for the CloudBus C++ Libraries.
//
//


#ifndef CLOUDBUS_Version_INCLUDED
#define CLOUDBUS_Version_INCLUDED


//
// Version Information
//
// Since 1.6.0, we're using Semantic Versioning 2.0
// (http://semver.org/spec/v2.0.0.html)
//
// Version format is 0xAABBCCDD, where
//    - AA is the major version number,
//    - BB is the minor version number,
//    - CC is the patch	version number, and
//    - DD is the pre-release designation/number.
//      The pre-release designation hex digits have a special meaning:
//      00: final/stable releases
//      Dx: development releases
//      Ax: alpha releases
//      Bx: beta releases
//
#define CLOUDBUS_VERSION 0x01000000


#endif // CLOUDBUS_Version_INCLUDED
