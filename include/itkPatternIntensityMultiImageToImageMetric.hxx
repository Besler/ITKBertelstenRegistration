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

#ifndef itkPatternIntensityMultiImageToImageMetric_hxx
#define itkPatternIntensityMultiImageToImageMetric_hxx

#include "itkPatternIntensityMultiImageToImageMetric.h"

namespace itk {

/**
 * Constructor
 */
  template <class TFixedImage, class TMovingImage>
  PatternIntensityMultiImageToImageMetric<TFixedImage,TMovingImage>
    ::PatternIntensityMultiImageToImageMetric()
  {
    itkDebugMacro("Constructor");
    m_Radius = 3;
    m_Sigma = 10;
  }

  template <class TFixedImage, class TMovingImage>
  typename PatternIntensityMultiImageToImageMetric<TFixedImage,TMovingImage>::BaseMetricPointer
  PatternIntensityMultiImageToImageMetric<TFixedImage,TMovingImage>::NewSingleMetric()
  {
    MetricPointer pattIntMetric = MetricType::New();
    pattIntMetric->SetRadius( this->m_Radius );
    pattIntMetric->SetSigma( this->m_Sigma );

    return static_cast<BaseMetricType*>( pattIntMetric.GetPointer() );
  }


  template <class TFixedImage, class TMovingImage>
  void
  PatternIntensityMultiImageToImageMetric<TFixedImage,TMovingImage>
    ::DoNumberRevision(void) const throw ( ExceptionObject )
  {
    Superclass::DoNumberRevision();

    if( m_Radius < 0 )
      itkExceptionMacro( << "Radius must be non-negative" );

    const unsigned int FImgTotal = this->m_MultiMetric.size();
    for( unsigned int f=0; f<FImgTotal; f++ )
      {
      MetricType* pattIntMetric = dynamic_cast<MetricType*>(
        this->m_MultiMetric[f].GetPointer() );

      if( pattIntMetric->GetRadius() != m_Radius )
        {
        itkExceptionMacro( << "Different radius values between "
          << "multi-metric and individual metrics. Call Initialize() to fix "
          << "this" );
        }

      if( pattIntMetric->GetSigma() != m_Sigma )
        {
        itkExceptionMacro( << "Different sigma values between "
          << "multi-metric and individual metrics. Call Initialize() to fix "
          << "this" );
        }
      } // for( unsigned int f=0; f<FImgTotal; f++ )
  }

/*
 * PrintSelf
 */
  template < typename TFixedImage, typename TMovingImage >
  void
  PatternIntensityMultiImageToImageMetric<TFixedImage,TMovingImage>
  ::PrintSelf(std::ostream& os, Indent indent) const
  {
    Superclass::PrintSelf( os, indent );

    os << indent << "Radius (in voxels): " << m_Radius << std::endl;
    os << indent << "Sigma: " << m_Sigma << std::endl;
  }

} // end namespace itk

#endif
