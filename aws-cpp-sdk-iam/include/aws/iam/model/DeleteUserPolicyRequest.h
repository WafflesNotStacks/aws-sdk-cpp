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
#include <aws/iam/IAM_EXPORTS.h>
#include <aws/iam/IAMRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace IAM
{
namespace Model
{

  /*
  */
  class AWS_IAM_API DeleteUserPolicyRequest : public IAMRequest
  {
  public:
    DeleteUserPolicyRequest();
    Aws::String SerializePayload() const override;


    /*
     <p>The name (friendly name, not ARN) identifying the user that the policy is embedded in.</p>
    */
    inline const Aws::String& GetUserName() const{ return m_userName; }

    /*
     <p>The name (friendly name, not ARN) identifying the user that the policy is embedded in.</p>
    */
    inline void SetUserName(const Aws::String& value) { m_userNameHasBeenSet = true; m_userName = value; }

    /*
     <p>The name (friendly name, not ARN) identifying the user that the policy is embedded in.</p>
    */
    inline void SetUserName(Aws::String&& value) { m_userNameHasBeenSet = true; m_userName = value; }

    /*
     <p>The name (friendly name, not ARN) identifying the user that the policy is embedded in.</p>
    */
    inline void SetUserName(const char* value) { m_userNameHasBeenSet = true; m_userName.assign(value); }

    /*
     <p>The name (friendly name, not ARN) identifying the user that the policy is embedded in.</p>
    */
    inline DeleteUserPolicyRequest& WithUserName(const Aws::String& value) { SetUserName(value); return *this;}

    /*
     <p>The name (friendly name, not ARN) identifying the user that the policy is embedded in.</p>
    */
    inline DeleteUserPolicyRequest& WithUserName(Aws::String&& value) { SetUserName(value); return *this;}

    /*
     <p>The name (friendly name, not ARN) identifying the user that the policy is embedded in.</p>
    */
    inline DeleteUserPolicyRequest& WithUserName(const char* value) { SetUserName(value); return *this;}

    /*
     <p>The name identifying the policy document to delete.</p>
    */
    inline const Aws::String& GetPolicyName() const{ return m_policyName; }

    /*
     <p>The name identifying the policy document to delete.</p>
    */
    inline void SetPolicyName(const Aws::String& value) { m_policyNameHasBeenSet = true; m_policyName = value; }

    /*
     <p>The name identifying the policy document to delete.</p>
    */
    inline void SetPolicyName(Aws::String&& value) { m_policyNameHasBeenSet = true; m_policyName = value; }

    /*
     <p>The name identifying the policy document to delete.</p>
    */
    inline void SetPolicyName(const char* value) { m_policyNameHasBeenSet = true; m_policyName.assign(value); }

    /*
     <p>The name identifying the policy document to delete.</p>
    */
    inline DeleteUserPolicyRequest& WithPolicyName(const Aws::String& value) { SetPolicyName(value); return *this;}

    /*
     <p>The name identifying the policy document to delete.</p>
    */
    inline DeleteUserPolicyRequest& WithPolicyName(Aws::String&& value) { SetPolicyName(value); return *this;}

    /*
     <p>The name identifying the policy document to delete.</p>
    */
    inline DeleteUserPolicyRequest& WithPolicyName(const char* value) { SetPolicyName(value); return *this;}

  private:
    Aws::String m_userName;
    bool m_userNameHasBeenSet;
    Aws::String m_policyName;
    bool m_policyNameHasBeenSet;
  };

} // namespace Model
} // namespace IAM
} // namespace Aws
