model.canvas {
    cube {
        motion (%2~1)
        rotate (x -1…1~0, y -1…1~0)
        back (%2~1)
        show (%2~0) <> shader.render.cubemap.on
    }
}
_menu.canvas {
    cube (sym "cube") {
        motion (sym "gyroscope")
        rotate (svg "icon.direction")
        back   (sym "cube")
        show   (sym "cube.fill")
    }
}
