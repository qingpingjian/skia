/*
 * Copyright 2018 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/**************************************************************************************************
 *** This file was autogenerated from GrLinearGradientLayout.fp; do not modify.
 **************************************************************************************************/
#include "GrLinearGradientLayout.h"
#include "glsl/GrGLSLFragmentProcessor.h"
#include "glsl/GrGLSLFragmentShaderBuilder.h"
#include "glsl/GrGLSLProgramBuilder.h"
#include "GrTexture.h"
#include "SkSLCPP.h"
#include "SkSLUtil.h"
class GrGLSLLinearGradientLayout : public GrGLSLFragmentProcessor {
public:
    GrGLSLLinearGradientLayout() {}
    void emitCode(EmitArgs& args) override {
        GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
        const GrLinearGradientLayout& _outer = args.fFp.cast<GrLinearGradientLayout>();
        (void)_outer;
        auto gradientMatrix = _outer.gradientMatrix();
        (void)gradientMatrix;
        SkString sk_TransformedCoords2D_0 = fragBuilder->ensureCoords2D(args.fTransformedCoords[0]);
        fragBuilder->codeAppendf("half t = half(%s.x);\n%s = half4(t, 1.0, 0.0, 0.0);\n",
                                 sk_TransformedCoords2D_0.c_str(), args.fOutputColor);
    }

private:
    void onSetData(const GrGLSLProgramDataManager& pdman,
                   const GrFragmentProcessor& _proc) override {}
};
GrGLSLFragmentProcessor* GrLinearGradientLayout::onCreateGLSLInstance() const {
    return new GrGLSLLinearGradientLayout();
}
void GrLinearGradientLayout::onGetGLSLProcessorKey(const GrShaderCaps& caps,
                                                   GrProcessorKeyBuilder* b) const {}
bool GrLinearGradientLayout::onIsEqual(const GrFragmentProcessor& other) const {
    const GrLinearGradientLayout& that = other.cast<GrLinearGradientLayout>();
    (void)that;
    if (fGradientMatrix != that.fGradientMatrix) return false;
    return true;
}
GrLinearGradientLayout::GrLinearGradientLayout(const GrLinearGradientLayout& src)
        : INHERITED(kGrLinearGradientLayout_ClassID, src.optimizationFlags())
        , fGradientMatrix(src.fGradientMatrix)
        , fCoordTransform0(src.fCoordTransform0) {
    this->addCoordTransform(&fCoordTransform0);
}
std::unique_ptr<GrFragmentProcessor> GrLinearGradientLayout::clone() const {
    return std::unique_ptr<GrFragmentProcessor>(new GrLinearGradientLayout(*this));
}

std::unique_ptr<GrFragmentProcessor> GrLinearGradientLayout::Make(const SkLinearGradient& grad,
                                                                  const GrFPArgs& args) {
    SkMatrix matrix;
    if (!grad.totalLocalMatrix(args.fPreLocalMatrix, args.fPostLocalMatrix)->invert(&matrix)) {
        return nullptr;
    }
    matrix.postConcat(grad.getGradientMatrix());
    return std::unique_ptr<GrFragmentProcessor>(new GrLinearGradientLayout(matrix));
}
