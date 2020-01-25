// https://doc.qt.io/qt-5/qtquick-scenegraph-openglunderqml-example.html

#include "renderer.hpp"

const char *vs =
    "attribute highp vec4 vertices;"
    "varying highp vec2 coords;"
    "void main() {"
    "   gl_Position = vertices;"
    "   coords = vertices.xy;"
    "}";

const char *fs =
    "uniform lowp float t;"
    "varying highp vec2 coords;"
    "void main() {"
    "   lowp float i = 1. - (pow(abs(coords.x), 4.) + pow(abs(coords.y), 4.));"
    "   i = smoothstep(t - 0.8, t + 0.8, i);"
    "   i = floor(i * 20.) / 20.;"
    "   gl_FragColor = vec4(coords * .5 + .5, i, i);"
    "}";

void Renderer::init()
{
    if (!program_.get())
    {
        initializeOpenGLFunctions();

        program_ = std::make_unique<QOpenGLShaderProgram>();

        program_.get()->addCacheableShaderFromSourceCode(QOpenGLShader::Vertex, vs);
        program_.get()->addCacheableShaderFromSourceCode(QOpenGLShader::Fragment, fs);

        program_.get()->bindAttributeLocation("vertices", 0);
        program_.get()->link();
    }
}

void Renderer::paint()
{
    window_->beginExternalCommands();
    program_->bind();
    program_->enableAttributeArray(0);

    float values[] = { -1, -1, 1, -1, -1, 1, 1, 1 };

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    program_->setAttributeArray(0, GL_FLOAT, values, 2);
    program_->setUniformValue("t", 1.f);
    glViewport(0, 0, viewport_size_.width(), viewport_size_.height());
    glDisable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    program_->disableAttributeArray(0);
    program_->release();

    window_->resetOpenGLState();

    window_->endExternalCommands();
}