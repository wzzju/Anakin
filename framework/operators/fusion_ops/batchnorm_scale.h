/* Copyright (c) 2018 Anakin Authors, Inc. All Rights Reserved.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0
   
   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License. 
*/

#ifndef ANAKIN_OPERATOR_BATCHNORM_SCALE_H
#define ANAKIN_OPERATOR_BATCHNORM_SCALE_H

#include "framework/core/base.h"
#include "framework/core/data_types.h"
#include "framework/core/operator/operator.h"
#include "utils/logger/logger.h"
#include "saber/funcs/scale.h"

namespace anakin {

namespace ops {

template<typename Ttype, Precision Ptype>
class BatchnormScaleHelper;

/// pooling op
/**
 * \brief BatchnormScaleHelper implementation class
 * public inherit Operator
 */
template<typename Ttype, Precision Ptype>
class BatchnormScale : public Operator<Ttype, Ptype> {
public:
    BatchnormScale() {}

    /// forward impl
    virtual void operator() (OpContext<Ttype> &ctx, 
                             const std::vector<Tensor4dPtr<Ttype> >& ins, 
                             std::vector<Tensor4dPtr<Ttype> >& outs) {
		LOG(ERROR) << "Not Impl Yet Operator BatchnormScale< Ttype("
				   << Ttype << "), Precision("<< Ptype <<") >";	
    }

    friend class BatchnormScaleHelper<Ttype, Ptype>;
};

/**
 * \brief BatchnormScale helper class to implement it
 * public inherit OperatorHelper
 * including init resource and shape size in BatchnormScaleHelper context
 */
template<typename Ttype, Precision Ptype>
class BatchnormScaleHelper : public OperatorHelper<Ttype, Ptype> {
public:
    BatchnormScaleHelper()=default;

    ~BatchnormScaleHelper() {}

    Status InitParam() override;

    /**
    * \brief initial all the resource needed by pooling
    * \param ctx stand for BatchnormScale operation context
    * \param ins stand for input tensor vector
    * \param outs stand for output tensor vector
    * \return status
    */
    Status Init(OpContext<Ttype> &ctx,
                const std::vector<Tensor4dPtr<Ttype> >& ins, 
                std::vector<Tensor4dPtr<Ttype> >& outs) override;

    /**
    * \brief infer the shape of output and input.
    * \param ins stand for input tensor vector
    * \param outs stand for output tensor vector
    * \return status
    */
    Status InferShape(const std::vector<Tensor4dPtr<Ttype> >& ins,
                      std::vector<Tensor4dPtr<Ttype> >& outs) override;

public:
    ///< _param_conv_batchnorm_scale stand for BatchnormScale parameter
    saber::ScaleParam<Tensor4d<Ttype>>  _param_scale;
    ///< _funcs_conv stand for BatchnormScale function 
    saber::Scale<Ttype, typename PrecisionWrapper<Ptype>::saber_type> _funcs_scale;
};

} /* namespace ops */

} /* namespace anakin */

#endif
