import QtQuick 2.15

Image {
    id: root
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
// Image {
//   id: root

//   property color color: "black"

//   layer.samplerName: "imgSource"
//   layer.effect: ShaderEffect {
// 	readonly property color color: root.color
// 	fragmentShader: "
// 		  varying mediump vec2 qt_TexCoord0;
// 		  uniform highp float qt_Opacity;
// 		  unifrom sampler2D imgSource;
// 		  uniform highp vec4 color;
// 		  void main() {
// 			highp vec4 pixelColor = texture2D(imgSource, qt_TexCoord0);
// 			gl_FragColor = color * pixelColor * qt_Opacity;
// 		  }"
// 		}
//   cache: true
//   smooth: true
//   layer.enabled:true
// }

