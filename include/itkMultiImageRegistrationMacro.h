/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#ifndef itkMultiImageRegistrationMacro_h
#define itkMultiImageRegistrationMacro_h

namespace itk {

#define itkGetConstStdVectorMacro(name,type) \
  virtual const type & Get##name () \
  { \
    itkDebugMacro("returning " << #name ); \
    return this->m_##name; \
  }

#define itkSetConstStdVectorMacro(name,type) \
  virtual void Set##name (const type & arg) \
  { \
    itkDebugMacro("setting " << #name ); \
    this->m_##name = arg; \
    this->Modified(); \
  }

#define itkAddToStdVectorMacro(name,type,vector) \
  virtual void Add##name ( const type & arg ) \
  { \
    itkDebugMacro("adding " << arg << " to " << #vector ); \
    this->m_##vector.push_back( arg ); \
    this->Modified(); \
  }

#define itkAddConstObjectToStdVectorMacro(name,type,vector) \
  virtual void Add##name ( const type* arg ) \
  { \
    itkDebugMacro("adding " << arg << " to " << #vector ); \
    this->m_##vector.push_back( arg ); \
    this->Modified(); \
  }

#define itkAddObjectToStdVectorMacro(name,type,vector) \
  virtual void Add##name ( type* arg ) \
  { \
    itkDebugMacro("adding " << arg << " to " << #vector ); \
    this->m_##vector.push_back( arg ); \
    this->Modified(); \
  }

} // end namespace itk

#endif // itkMultiImageRegistrationMacro_h
