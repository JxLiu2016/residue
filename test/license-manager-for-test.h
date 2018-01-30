//
//  license-manager-for-test.h
//  Residue
//
//  Copyright (c) 2017-present Muflihun Labs
//
//  Author: @abumusamq
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#ifndef LICENSE_MANAGER_FOR_TEST_H
#define LICENSE_MANAGER_FOR_TEST_H

#include "test.h"
#include "deps/licensepp/include/base-license-manager.h"
#include "deps/licensepp/include/issuing-authority.h"

using namespace licensepp;

class LicenseManagerKeysForTest
{
public:
    static const unsigned char LICENSE_MANAGER_SIGNATURE_KEY[];

    static const std::vector<IssuingAuthority> LICENSE_ISSUING_AUTHORITIES;
};

const unsigned char LicenseManagerKeysForTest::LICENSE_MANAGER_SIGNATURE_KEY[] =
{
    0x82, 0xF3, 0x6C, 0x25, 0xA9, 0x12, 0x38, 0x9A, 0xBF, 0xF8, 0x09, 0x1C, 0x75, 0x93, 0x03, 0xD2
};

const std::vector<IssuingAuthority> LicenseManagerKeysForTest::LICENSE_ISSUING_AUTHORITIES = {
    IssuingAuthority("unittest-issuer", "Muflihun Labs (development)", "LS0tLS1CRUdJTiBSU0EgUFJJVkFURSBLRVktLS0tLQpNSUlDV3dJQkFBS0JnUUMrTU9RbGhUUlhRTXRuK1JpdjNwVWNWdmdZdkpiWG5SeHdSL24xcTFPR1llUWlEdVY4CmlOOVcyQlVDQWVjVE1CVEJMK0xZSndpMnErWEVWclZZZjF6NTVPRWpicmJyK3hRQitJYU5uNTIzWUpRRGdQd1IKU0ROMnp5dzhmSDRBUVVENjk3VnRYamJaVXFaL1ZOZU1iaFJoRnhJV2lkMDVIVkE1THM5bkdFMllNd0lCRVFLQgpnRTVRWGZGVTkyODR6RG5mQ2lwTWw4QmdDODN6VFN1YkM3WERTTTZSMXhrM1hlL29CQ1E0Vy9hVk5kT21ialVUCnpFK01NRHJpNVhoazVpT3JPNXpwSmtnUjJpVGszb2xJK1YvUVNacXBnZ2xBRnJ5aVMzVW1IMTlLVmVKdERaTmgKK2ZtU21WL0Y0T0xhNTFIVTY5eEYzZUdTRmlMVnNiY2ZMUVhtdVpUNDBJNDVBa0VBMWVkMDJOdDd0VUp2VU5vdApoWGUwTk1FTWFUdFZsbVk3WHFxcTNNOG5kRFhoTkxmL1loVFQ1MVNRQkp6U1hYa2pNRnI1NU5NclhQMkxjdnFkClhTeXNwd0pCQU9PZXdyTXN0U2JocWZiNW4xbnFOZGxTbXJJdURPZUJDdUNNYTd0cFRrelFseFhTRjYzYlRETWcKS0pSSEVOU2s5WVB2RVRCYWRaa3VldFNrWC9FbWJaVUNRUUN3S0FYZnc4OUorbm5LSFJadDZodnZOWkhBRXI3MApWRERrakl5MTE4WWpkNnBucHBZVWlaOXpOcFM0Z1NXMlk4S2dTdXZwbnRocXNxOFRaUG9RZnlURkFrQnJIWWpNCnliNm80cXBXR3gzUDliNzgyNVFYblRNL3hFRmFuRzd1eUNUWTJxRnpyaWxDd1kxRlBFOVUxaVlKdHdvZitBZ1cKd1NoSUZkOXpJQzBtTURPUkFrRUFnck92a2F6ZHJkVm0rT3ViUksrcUFyb2I0anJzWS9HQURiVE9rMkZmZndzQwpRd1NGdE9TcnkvZjhDRDRuRkcySDh6ekRrQjFvZUc3Z1ZPdC81R2dscEE9PQotLS0tLUVORCBSU0EgUFJJVkFURSBLRVktLS0tLQo=:LS0tLS1CRUdJTiBQVUJMSUMgS0VZLS0tLS0KTUlHZE1BMEdDU3FHU0liM0RRRUJBUVVBQTRHTEFEQ0Jod0tCZ1FDK01PUWxoVFJYUU10bitSaXYzcFVjVnZnWQp2SmJYblJ4d1IvbjFxMU9HWWVRaUR1VjhpTjlXMkJVQ0FlY1RNQlRCTCtMWUp3aTJxK1hFVnJWWWYxejU1T0VqCmJyYnIreFFCK0lhTm41MjNZSlFEZ1B3UlNETjJ6eXc4Zkg0QVFVRDY5N1Z0WGpiWlVxWi9WTmVNYmhSaEZ4SVcKaWQwNUhWQTVMczluR0UyWU13SUJFUT09Ci0tLS0tRU5EIFBVQkxJQyBLRVktLS0tLQo=", 24U, true), // 1 day - no-secret
};


class LicenseManagerForTest : public BaseLicenseManager<LicenseManagerKeysForTest>
{
public:
    LicenseManagerForTest()
        : BaseLicenseManager()
    {
    }
};

#endif // LICENSE_MANAGER_FOR_TEST_H
