//
//  zlib.h
//  Residue
//
//  Copyright © 2017 Muflihun Labs
//

#ifndef ZLib_h
#define ZLib_h

#include <string>
#include "src/static-base.h"

namespace residue {

///
/// \brief ZLib wrappers
///
class ZLib final : StaticBase
{
public:

    ///
    /// \brief Deflate
    ///
    static std::string compress(const std::string& data);

    ///
    /// \brief Inflate
    ///
    static std::string decompress(const std::string& data);

    ///
    /// \brief Compress file (Deflate)
    ///
    static bool compressFile(const std::string& gzoutFilename, const std::string& inputFile);

};
}

#endif /* ZLib_h */