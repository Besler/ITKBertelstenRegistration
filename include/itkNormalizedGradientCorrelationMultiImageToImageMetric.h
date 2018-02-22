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

#ifndef itkNormalizedGradientCorrelationMultiImageToImageMetric_h
#define itkNormalizedGradientCorrelationMultiImageToImageMetric_h

#include "itkMultiImageToImageMetric.h"
#include "itkNormalizedGradientCorrelationImageToImageMetric.h"

namespace itk {

/** \class NormalizedGradientCorrelationMultiImageToImageMetric
 *
 * \brief Version of the normalized gradient correlation metric for registrations with multiple fixed images.
 * 
 * \ingroup BertelstenRegistration
 */
template < class TFixedImage, class TMovingImage >
class ITK_EXPORT NormalizedGradientCorrelationMultiImageToImageMetric :
public MultiImageToImageMetric<TFixedImage,TMovingImage>
{
public:
  /** Standard class typedefs */
  typedef NormalizedGradientCorrelationMultiImageToImageMetric                Self;
  typedef MultiImageToImageMetric<TFixedImage,TMovingImage> Superclass;
  typedef SmartPointer<Self>                                Pointer;
  typedef SmartPointer<const Self>                          ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(NormalizedGradientCorrelationMultiImageToImageMetric, MultiImageToImageMetric);

  /** Types defined by this class */
  typedef NormalizedGradientCorrelationImageToImageMetric< TFixedImage, TMovingImage > MetricType;

protected:
  NormalizedGradientCorrelationMultiImageToImageMetric() {  itkDebugMacro("Constructor"); }
  virtual ~NormalizedGradientCorrelationMultiImageToImageMetric() {};

  itkNewSingleMetricMacro(MetricType);

private:
  NormalizedGradientCorrelationMultiImageToImageMetric(const Self&); //purposely not implemented
  void operator=(const Self&);          //purposely not implemented
};
} //namespace itk

#endif
