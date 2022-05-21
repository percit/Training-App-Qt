import QtQuick 2.3

Image {
    id: root
    //TODO fix coloring (there are errors when layer.enabled: true)
    property color color: "transparent"

    layer.samplerName: "imgSource"
    layer.effect: ShaderEffect {
    readonly property color color: root.color
    fragmentShader: "
    varying mediump vec2 qt_TexCoord0;
    uniform highp float qt_Opacity;
    uniform sampler2D imgSource;
    uniform highp vec4 color;
    void main() {
    highp vec4 pixelColor = texture2D(imgSource, qt_TexCoord0);
    gl_FragColor = color * pixelColor.a * qt_Opacity;
}"
}

readonly property color transparentColor: "transparent"
layer.enabled: color != transparentColor
cache: true
smooth: true
}
