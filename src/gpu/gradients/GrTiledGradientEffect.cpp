/*
 * Copyright 2018 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/**************************************************************************************************
 *** This file was autogenerated from GrTiledGradientEffect.fp; do not modify.
 **************************************************************************************************/
#include "GrTiledGradientEffect.h"
#include "glsl/GrGLSLFragmentProcessor.h"
#include "glsl/GrGLSLFragmentShaderBuilder.h"
#include "glsl/GrGLSLProgramBuilder.h"
#include "GrTexture.h"
#include "SkSLCPP.h"
#include "SkSLUtil.h"
class GrGLSLTiledGradientEffect : public GrGLSLFragmentProcessor {
public:
    GrGLSLTiledGradientEffect() {}
    void emitCode(EmitArgs& args) override {
        GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
        const GrTiledGradientEffect& _outer = args.fFp.cast<GrTiledGradientEffect>();
        (void)_outer;
        auto mirror = _outer.mirror();
        (void)mirror;
        SkString _child1("_child1");
        this->emitChild(1, &_child1, args);
        fragBuilder->codeAppendf(
                "half4 t = %s;\nif (t.y < 0.0) {\n    %s = half4(0.0);\n} else {\n    @if (%s) {\n "
                "       half t_1 = t.x - 1.0;\n        half tiled_t = (float(t_1) - 2.0 * "
                "floor(float(float(t_1) * 0.5))) - 1.0;\n        if "
                "(sk_Caps.mustDoOpBetweenFloorAndAbs) {\n            tiled_t = "
                "half(clamp(float(tiled_t), -1.0, 1.0));\n        }\n        t.x = "
                "half(abs(float(tiled_t)));\n    } else {\n        t.x = "
                "half(fract(float(t.x)));\n    }",
                _child1.c_str(), args.fOutputColor, (_outer.mirror() ? "true" : "false"));
        SkString _input0("t");
        SkString _child0("_child0");
        this->emitChild(0, _input0.c_str(), &_child0, args);
        fragBuilder->codeAppendf("\n    %s = %s;\n}\n", args.fOutputColor, _child0.c_str());
    }

private:
    void onSetData(const GrGLSLProgramDataManager& pdman,
                   const GrFragmentProcessor& _proc) override {}
};
GrGLSLFragmentProcessor* GrTiledGradientEffect::onCreateGLSLInstance() const {
    return new GrGLSLTiledGradientEffect();
}
void GrTiledGradientEffect::onGetGLSLProcessorKey(const GrShaderCaps& caps,
                                                  GrProcessorKeyBuilder* b) const {
    b->add32((int32_t)fMirror);
}
bool GrTiledGradientEffect::onIsEqual(const GrFragmentProcessor& other) const {
    const GrTiledGradientEffect& that = other.cast<GrTiledGradientEffect>();
    (void)that;
    if (fMirror != that.fMirror) return false;
    return true;
}
GrTiledGradientEffect::GrTiledGradientEffect(const GrTiledGradientEffect& src)
        : INHERITED(kGrTiledGradientEffect_ClassID, src.optimizationFlags()), fMirror(src.fMirror) {
    this->registerChildProcessor(src.childProcessor(0).clone());
    this->registerChildProcessor(src.childProcessor(1).clone());
}
std::unique_ptr<GrFragmentProcessor> GrTiledGradientEffect::clone() const {
    return std::unique_ptr<GrFragmentProcessor>(new GrTiledGradientEffect(*this));
}
