#pragma once

#include "solutions/untexturedobjectssoln.h"

// --------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------
class UntexturedObjectsGLDrawLoop : public UntexturedObjectsSolution
{
public:
    UntexturedObjectsGLDrawLoop();
    virtual ~UntexturedObjectsGLDrawLoop() { }

    virtual bool Init(const std::vector<UntexturedObjectsProblem::Vertex>& _vertices,
                      const std::vector<UntexturedObjectsProblem::Index>& _indices,
                      size_t _objectCount) override;

    virtual void Render(const std::vector<Matrix>& _transforms);
    virtual void Shutdown();

    virtual std::string GetName() const { return "GLDrawLoop"; }
    virtual bool SupportsApi(EGfxApi _api) const override { return IsOpenGL(_api); }

private:
    GLuint m_ib;
    GLuint m_vb;
    GLuint m_varray;
    GLuint m_drawid;
    GLuint m_prog;

    GLuint m_transform_buffer;

    struct UniformLocations {
        GLuint ViewProjection;
        UniformLocations() { memset(this, 0, sizeof(*this)); }
    } mUniformLocation;
};
