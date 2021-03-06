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
#include <aws/lambda/model/InvokeRequest.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>
#include <aws/core/utils/HashingUtils.h>

#include <utility>

using namespace Aws::Lambda::Model;
using namespace Aws::Utils::Stream;
using namespace Aws::Utils;
using namespace Aws;

InvokeRequest::InvokeRequest() : 
    m_functionNameHasBeenSet(false),
    m_invocationTypeHasBeenSet(false),
    m_logTypeHasBeenSet(false),
    m_clientContextHasBeenSet(false)
{
}


Aws::Http::HeaderValueCollection InvokeRequest::GetRequestSpecificHeaders() const
{
  Aws::Http::HeaderValueCollection headers;
  Aws::StringStream ss;
  if(m_invocationTypeHasBeenSet)
  {
   headers.insert(Aws::Http::HeaderValuePair("x-amz-invocation-type", InvocationTypeMapper::GetNameForInvocationType(m_invocationType)));
  }

  if(m_logTypeHasBeenSet)
  {
   headers.insert(Aws::Http::HeaderValuePair("x-amz-log-type", LogTypeMapper::GetNameForLogType(m_logType)));
  }

  if(m_clientContextHasBeenSet)
  {
   ss << m_clientContext;
   headers.insert(Aws::Http::HeaderValuePair("x-amz-client-context", ss.str()));
   ss.str("");
  }

  return std::move(headers);

}
