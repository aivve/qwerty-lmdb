// Copyright (c) 2019-2020, Blur Network
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include "Common/StringTools.h"
#include "CryptoNote.h"

namespace CryptoNote {

  //----------------------------------------------------------------
  BinaryArray hex_to_bin(const std::string &input)
  {
    CryptoNote::BinaryArray out;
    size_t len = input.length();
    for(size_t i = 0; i < len; i += 2) {
      std::istringstream strm(input.substr(i, 2));
      uint8_t x;
      strm >> std::hex >> x;
      out.push_back(x);
    }
    return out;
  }
  //----------------------------------------------------------------
  std::string bin_to_hex(BinaryArray &input)
  {
   //should probably have this return bool so that we can handle errors on false
    static const char characters[] = "0123456789abcdef";
    std::string ret(input.size() * 2, 0);
    char *buffer = const_cast<char *>(ret.data());

    for (const auto &each_byte : input) {
      *buffer++ = characters[each_byte >> 4];
      *buffer++ = characters[each_byte & 0x0F];
    }
    return ret;
  }

} // namespace CryptoNote