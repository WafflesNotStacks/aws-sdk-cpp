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
#include <aws/redshift/model/DescribeClusterParameterGroupsResult.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>

#include <utility>

using namespace Aws::Redshift::Model;
using namespace Aws::Utils::Xml;
using namespace Aws::Utils;
using namespace Aws;

DescribeClusterParameterGroupsResult::DescribeClusterParameterGroupsResult()
{
}

DescribeClusterParameterGroupsResult::DescribeClusterParameterGroupsResult(const AmazonWebServiceResult<XmlDocument>& result)
{
  *this = result;
}

DescribeClusterParameterGroupsResult& DescribeClusterParameterGroupsResult::operator =(const AmazonWebServiceResult<XmlDocument>& result)
{
  const XmlDocument& xmlDocument = result.GetPayload();
  XmlNode rootNode = xmlDocument.GetRootElement();
  XmlNode resultNode = rootNode;
  if (rootNode.GetName() != "DescribeClusterParameterGroupsResult")
  {
    resultNode = rootNode.FirstChild("DescribeClusterParameterGroupsResult");
  }

  if(!resultNode.IsNull())
  {
    XmlNode markerNode = resultNode.FirstChild("Marker");
    if(!markerNode.IsNull())
    {
      m_marker = StringUtils::Trim(markerNode.GetText().c_str());
    }
    XmlNode parameterGroupsNode = resultNode.FirstChild("ParameterGroups");
    if(!parameterGroupsNode.IsNull())
    {
      XmlNode parameterGroupsMember = parameterGroupsNode.FirstChild("ClusterParameterGroup");
      while(!parameterGroupsMember.IsNull())
      {
        m_parameterGroups.push_back(parameterGroupsMember);
        parameterGroupsMember = parameterGroupsMember.NextNode("ClusterParameterGroup");
      }

    }
  }

  XmlNode responseMetadataNode = rootNode.FirstChild("ResponseMetadata");
  m_responseMetadata = responseMetadataNode;

  return *this;
}
