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
#pragma once
#include <aws/ec2/EC2_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/ec2/model/ResponseMetadata.h>

namespace Aws
{
template<typename RESULT_TYPE>
class AmazonWebServiceResult;

namespace Utils
{
namespace Xml
{
  class XmlDocument;
} // namespace Xml
} // namespace Utils
namespace EC2
{
namespace Model
{
  /*
    $shape.documentation
  */
  class AWS_EC2_API RegisterImageResponse
  {
  public:
    RegisterImageResponse();
    RegisterImageResponse(const AmazonWebServiceResult<Aws::Utils::Xml::XmlDocument>& result);
    RegisterImageResponse& operator=(const AmazonWebServiceResult<Aws::Utils::Xml::XmlDocument>& result);

    /*
     <p>The ID of the newly registered AMI.</p>
    */
    inline const Aws::String& GetImageId() const{ return m_imageId; }

    /*
     <p>The ID of the newly registered AMI.</p>
    */
    inline void SetImageId(const Aws::String& value) { m_imageId = value; }

    /*
     <p>The ID of the newly registered AMI.</p>
    */
    inline void SetImageId(Aws::String&& value) { m_imageId = value; }

    /*
     <p>The ID of the newly registered AMI.</p>
    */
    inline void SetImageId(const char* value) { m_imageId.assign(value); }

    /*
     <p>The ID of the newly registered AMI.</p>
    */
    inline RegisterImageResponse& WithImageId(const Aws::String& value) { SetImageId(value); return *this;}

    /*
     <p>The ID of the newly registered AMI.</p>
    */
    inline RegisterImageResponse& WithImageId(Aws::String&& value) { SetImageId(value); return *this;}

    /*
     <p>The ID of the newly registered AMI.</p>
    */
    inline RegisterImageResponse& WithImageId(const char* value) { SetImageId(value); return *this;}

    
    inline const ResponseMetadata& GetResponseMetadata() const{ return m_responseMetadata; }

    
    inline void SetResponseMetadata(const ResponseMetadata& value) { m_responseMetadata = value; }

    
    inline void SetResponseMetadata(ResponseMetadata&& value) { m_responseMetadata = value; }

    
    inline RegisterImageResponse& WithResponseMetadata(const ResponseMetadata& value) { SetResponseMetadata(value); return *this;}

    
    inline RegisterImageResponse& WithResponseMetadata(ResponseMetadata&& value) { SetResponseMetadata(value); return *this;}

  private:
    Aws::String m_imageId;
    ResponseMetadata m_responseMetadata;
  };

} // namespace Model
} // namespace EC2
} // namespace Aws