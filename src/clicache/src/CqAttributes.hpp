/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "gf_defs.hpp"
#include <gfcpp/CqAttributes.hpp>
#include "impl/NativeWrapper.hpp"


using namespace System;

namespace Apache
{
  namespace Geode
  {
    namespace Client
    {

      generic<class TKey, class TResult>
      interface class ICqListener;

      /// <summary>
      /// Defines attributes for configuring a cq.
      /// </summary>
      generic<class TKey, class TResult>
      public ref class CqAttributes sealed
        : public Internal::SBWrap<apache::geode::client::CqAttributes>
      {
      public:

        /// <summary>
        /// get all listeners in this attributes
        /// </summary>
        virtual array<Client::ICqListener<TKey, TResult>^>^ getCqListeners();

      internal:

        /// <summary>
        /// Internal factory function to wrap a native object pointer inside
        /// this managed class with null pointer check.
        /// </summary>
        /// <param name="nativeptr">The native object pointer</param>
        /// <returns>
        /// The managed wrapper object; null if the native pointer is null.
        /// </returns>
        inline static CqAttributes<TKey, TResult>^ Create( apache::geode::client::CqAttributes* nativeptr )
        {
          if (nativeptr == nullptr)
          {
            return nullptr;
          }
          return gcnew CqAttributes( nativeptr );
        }


      private:

        /// <summary>
        /// Private constructor to wrap a native object pointer
        /// </summary>
        /// <param name="nativeptr">The native object pointer</param>
        inline CqAttributes( apache::geode::client::CqAttributes* nativeptr )
          : SBWrap( nativeptr ) { }
      };
    }  // namespace Client
  }  // namespace Geode
}  // namespace Apache

