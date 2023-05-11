model {
    canvas {
        plato {
            shade {
                phase  (x 0…1, y 0.9…1.1)
                convex (val 0.9…1.1 = 1) <~ sky.main.anim
                colors (x 0…255=0, y 0…1=0)
                shadow (x 0…1=0, y 0…1=0)
                invert (val 0…1=1)
            }
            zoom  (val 0…1=1) <~ sky.main.anim
            wire  (tog 0…1)
            morph (tog 0…1=1)
            show  (tog 0…1=0)  <> shader.render.plato.on
        }
    }
}
_menu.canvas {
    plato(svg "icon.plato.wire") {
        shade (svg "icon.peacock") {
            phase  (sym "calendar.day.timeline.left")
            convex (svg "icon.convex")
            colors (sym "figure.stair.stepper")
            shadow (sym "shadow")
            invert (sym "circle.lefthalf.filled")
        }
        zoom  (svg "icon.zoom")
        morph (svg "icon.counter")
        wire  (svg "icon.wireframe")
        show  (svg "icon.plato.show")
    }
}
