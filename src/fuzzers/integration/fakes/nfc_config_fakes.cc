#include <fuzzer/FuzzedDataProvider.h>

#include "nfc_config.h"

extern FuzzedDataProvider* g_fuzzed_data;

bool NfcConfig::hasKey(const std::string&) {
  return g_fuzzed_data->ConsumeBool();
}

unsigned NfcConfig::getUnsigned(const std::string&) {
  return g_fuzzed_data->ConsumeIntegral<unsigned>();
}

unsigned NfcConfig::getUnsigned(const std::string&, unsigned default_value) {
  if (g_fuzzed_data->ConsumeBool())
    return g_fuzzed_data->ConsumeIntegral<unsigned>();
  return default_value;
}
