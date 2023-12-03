#pragma once

#include <string>
#include <string_view>
#include <tuple>

namespace LZSS
{

//Types:
struct Encoded
{
  std::string CompressedStr;

  struct DecodeTableT
  {
  } DecodeTable;
};

//IO operators:
std::istream& operator>>(std::istream& is, Encoded::DecodeTableT& table)
{
  return is;
}

std::ostream& operator<<(std::ostream& os, const Encoded::DecodeTableT& table)
{
  return os;
}

std::istream& operator>>(std::istream& is, Encoded& enc)
{
  is >> enc.DecodeTable;
  is >> enc.CompressedStr;
  return is;
}

std::ostream& operator<<(std::ostream& os, const Encoded& enc)
{
  os << enc.DecodeTable;
  os << enc.CompressedStr;
  return os;
}

//Transformation functions:
Encoded Encode(std::string_view inStr)
{
  return {std::string{inStr}, {}};
}

std::string Decode(const Encoded& enc)
{
  return enc.CompressedStr;
}

} //namespace: LZSS


