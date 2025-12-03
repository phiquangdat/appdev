from pathlib import Path
from svgelements import SVG, Path as SvgPath
from shapely.geometry import Polygon
import xml.etree.ElementTree as ET

SVG_PATH = Path("./vietnam.svg")
OUT_PATH = Path("./vietnam_with_centroid.svg")

svg = SVG.parse(SVG_PATH)

polygons = []

for element in svg.elements():
    if isinstance(element, SvgPath):
        pts = list(element.as_points())
        if len(pts) > 3:
            poly = Polygon([(p.x, p.y) for p in pts])
            if not poly.is_valid:
                poly = poly.buffer(0)  
            if not poly.is_empty:
                polygons.append(poly)

def explode(poly): # Splits MultiPolygons into individual Polygons
    if poly.geom_type == "Polygon":
        return [poly]
    return list(poly.geoms)

all_polys = []
for poly in polygons:
    all_polys.extend(explode(poly))

def polygon_centroid(points):
    A_sum = 0
    Cx_sum = 0
    Cy_sum = 0
    n = len(points)

    for i in range(n):
        x0, y0 = points[i]
        x1, y1 = points[(i + 1) % n]
        cross = x0 * y1 - x1 * y0
        A_sum += cross
        Cx_sum += (x0 + x1) * cross
        Cy_sum += (y0 + y1) * cross

    A = A_sum / 2
    Cx = Cx_sum / (6 * A)
    Cy = Cy_sum / (6 * A)
    return Cx, Cy, abs(A)

total_area = 0
Cx_total = 0
Cy_total = 0

for poly in all_polys:
    pts = list(poly.exterior.coords)
    cx, cy, area = polygon_centroid(pts)

    total_area += area
    Cx_total += cx * area
    Cy_total += cy * area

cx = Cx_total / total_area
cy = Cy_total / total_area

print(f"Centroid: {cx:.2f}, {cy:.2f}")

ET.register_namespace("", "http://www.w3.org/2000/svg")
tree = ET.parse(SVG_PATH)
root = tree.getroot()

circle = ET.Element("{http://www.w3.org/2000/svg}circle", {
    "cx": str(cx),
    "cy": str(cy),
    "r": "60",
    "stroke": "red",
    "fill": "none",
    "stroke-width": "10"
})

root.append(circle)
tree.write(OUT_PATH, encoding="utf-8", xml_declaration=True)
print("Done:", OUT_PATH)
