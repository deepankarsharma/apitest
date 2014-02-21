#pragma once

#include "solutions/dynamicstreamingsoln.h"

// --------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------
class DynamicStreamingPersistent : public DynamicStreamingSolution
{
public:
    DynamicStreamingPersistent();
    virtual ~DynamicStreamingPersistent();

    virtual bool Init() override;
    virtual void Render(const std::vector<Vec2>& _vertices) override;
    virtual void Shutdown() override;

    // The name of this solution.
    virtual std::string GetName() const override { return "DynamicStreamingPersistent"; }

private:
    struct Constants
    {
        float width;
        float height;
        float pad[2];
    };

    GLuint mUniformBuffer;
    GLuint mVertexBuffer;
    GLuint mProgram;

    struct UniformLocations {
        GLuint CB0;
        UniformLocations() { memset(this, 0, sizeof(*this)); }
    } mUniformLocation;

    void* mVertexDataPtr;
};
