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
#include <aws/ec2/model/DescribeVpnConnectionsResponse.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>

#include <utility>

using namespace Aws::EC2::Model;
using namespace Aws::Utils::Xml;
using namespace Aws::Utils;
using namespace Aws;

DescribeVpnConnectionsResponse::DescribeVpnConnectionsResponse()
{
}

DescribeVpnConnectionsResponse::DescribeVpnConnectionsResponse(const AmazonWebServiceResult<XmlDocument>& result)
{
  *this = result;
}

DescribeVpnConnectionsResponse& DescribeVpnConnectionsResponse::operator =(const AmazonWebServiceResult<XmlDocument>& result)
{
  const XmlDocument& xmlDocument = result.GetPayload();
  XmlNode rootNode = xmlDocument.GetRootElement();
  XmlNode resultNode = rootNode;
  if (rootNode.GetName() != "DescribeVpnConnectionsResponse")
  {
    resultNode = rootNode.FirstChild("DescribeVpnConnectionsResponse");
  }

  if(!resultNode.IsNull())
  {
    XmlNode vpnConnectionsNode = resultNode.FirstChild("VpnConnections");
    if(!vpnConnectionsNode.IsNull())
    {
      XmlNode vpnConnectionsMember = vpnConnectionsNode.FirstChild("item");
      while(!vpnConnectionsMember.IsNull())
      {
        m_vpnConnections.push_back(vpnConnectionsMember);
        vpnConnectionsMember = vpnConnectionsMember.NextNode("item");
      }

    }
  }

  XmlNode responseMetadataNode = rootNode.FirstChild("ResponseMetadata");
  m_responseMetadata = responseMetadataNode;

  return *this;
}
