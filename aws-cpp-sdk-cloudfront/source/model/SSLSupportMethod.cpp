/*
* Copyright 2010-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/
#include <aws/cloudfront/model/SSLSupportMethod.h>
#include <aws/core/utils/HashingUtils.h>

using namespace Aws::Utils;

static const int sni_only_HASH = HashingUtils::HashString("sni-only");
static const int vip_HASH = HashingUtils::HashString("vip");

namespace Aws
{
namespace CloudFront
{
namespace Model
{
namespace SSLSupportMethodMapper
{
SSLSupportMethod GetSSLSupportMethodForName(const Aws::String& name)
{
  int hashCode = HashingUtils::HashString(name.c_str());

  if (hashCode == sni_only_HASH)
  {
    return SSLSupportMethod::sni_only;
  }
  else if (hashCode == vip_HASH)
  {
    return SSLSupportMethod::vip;
  }

  return SSLSupportMethod::NOT_SET;
}

Aws::String GetNameForSSLSupportMethod(SSLSupportMethod value)
{
  switch(value)
  {
  case SSLSupportMethod::sni_only:
    return "sni-only";
  case SSLSupportMethod::vip:
    return "vip";
  default:
    return "";
  }
}

} // namespace SSLSupportMethodMapper
} // namespace Model
} // namespace CloudFront
} // namespace Aws
