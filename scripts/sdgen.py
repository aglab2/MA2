import json

COURSE_CE = 1 
COURSE_WC = 2
COURSE_PL = 3
COURSE_MH = 4
COURSE_GF = 5
COURSE_PH = 6
COURSE_MS = 7
COURSE_AQ = 8
COURSE_HB = 9
COURSE_PC = 10
COURSE_DC = 11
COURSE_EE = 12
COURSE_MHE = 13
COURSE_CG = 14
COURSE_FR = 15
COURSE_SS2 = 16
COURSE_IG = 17
COURSE_DL = 18
COURSE_SO = 19
COURSE_RH = 20
COURSE_EQ = 21
COURSE_LC = 22
COURSE_WB = 23
COURSE_SH = 24
COURSE_WJ = 25
COURSE_SR = 26
COURSE_MSP = 27
COURSE_CW = 28
COURSE_FC = 29
COURSE_SS1 = 30
COURSE_CCT = 31
COURSE_CCE = 32
COURSE_CCR = 33
COURSE_CCK = 34
COURSE_CCS = 35
COURSE_LB = 36
COURSE_LF = 37
COURSE_GH = 38
COURSE_CHAO = 39
COURSE_GG = 40

class StarCount:
    def __init__(self, stars = 0, goal = False, checkpoints = 0, extra = False, has100 = False):
        self.stars = stars
        self.goal = goal
        self.checkpoints = checkpoints
        self.extra = extra
        self.has100 = has100

course = {}
course[ COURSE_AQ ] = StarCount( stars = 22, checkpoints = 4, has100 = True )
course[ COURSE_CCE ] = StarCount( stars = 12, checkpoints = 1, goal = True )
course[ COURSE_CCK ] = StarCount( stars = 12, checkpoints = 1, goal = True )
course[ COURSE_CCR ] = StarCount( stars = 9, checkpoints = 1, goal = True )
course[ COURSE_CCS ] = StarCount( stars = 8, checkpoints = 1, goal = True )
course[ COURSE_CCT ] = StarCount( stars = 7, checkpoints = 1, goal = True )
course[ COURSE_CE ] = StarCount( stars = 23, checkpoints = 5, goal = True, has100 = True )
course[ COURSE_CG ] = StarCount( stars = 27, checkpoints = 5, goal = True, has100 = True )
course[ COURSE_CHAO ] = StarCount( stars = 13, checkpoints = 4, has100 = True )
course[ COURSE_CW ] = StarCount( stars = 26, checkpoints = 8, goal = True, has100 = True )
course[ COURSE_DC ] = StarCount( stars = 27, checkpoints = 5, has100 = True )
course[ COURSE_DL ] = StarCount( stars = 24, checkpoints = 3, has100 = True )
course[ COURSE_EE ] = StarCount( stars = 20, checkpoints = 5, goal = True, has100 = True )
course[ COURSE_EQ ] = StarCount( stars = 28, checkpoints = 3, has100 = True )
course[ COURSE_FC ] = StarCount( stars = 34, checkpoints = 8, goal = True, has100 = True )
course[ COURSE_FR ] = StarCount( stars = 38, checkpoints = 5, goal = True, has100 = True )
course[ COURSE_GF ] = StarCount( stars = 26, checkpoints = 6, goal = True, extra = True, has100 = True )
course[ COURSE_GG ] = StarCount( stars = 1 )
course[ COURSE_GH ] = StarCount( stars = 22, checkpoints = 2, goal = True, has100 = True )
course[ COURSE_HB ] = StarCount( stars = 30, checkpoints = 5, goal = True, has100 = True )
course[ COURSE_IG ] = StarCount( stars = 18, checkpoints = 3, goal = True, has100 = True )
course[ COURSE_LB ] = StarCount( stars = 1 )
course[ COURSE_LC ] = StarCount( stars = 20, checkpoints = 3, goal = True, has100 = True )
course[ COURSE_LF ] = StarCount( stars = 0, goal = True )
course[ COURSE_MH ] = StarCount( stars = 28, checkpoints = 5, goal = True, has100 = True )
course[ COURSE_MHE ] = StarCount( stars = 25, checkpoints = 3, has100 = True )
course[ COURSE_MS ] = StarCount( stars = 23, checkpoints = 5, goal = True, has100 = True )
course[ COURSE_MSP ] = StarCount( stars = 26, checkpoints = 5, has100 = True )
course[ COURSE_PC ] = StarCount( stars = 25, checkpoints = 6, goal = True, has100 = True )
course[ COURSE_PH ] = StarCount( stars = 25, checkpoints = 4, has100 = True )
course[ COURSE_PL ] = StarCount( stars = 21, checkpoints = 5, goal = True, has100 = True )
course[ COURSE_RH ] = StarCount( stars = 26, checkpoints = 5, goal = True, has100 = True )
course[ COURSE_SH ] = StarCount( stars = 24, checkpoints = 3, has100 = True )
course[ COURSE_SO ] = StarCount( stars = 27, checkpoints = 3, goal = True, has100 = True )
course[ COURSE_SR ] = StarCount( stars = 28, checkpoints = 4, goal = True, has100 = True )
course[ COURSE_SS1 ] = StarCount( stars = 1 )
course[ COURSE_SS2 ] = StarCount( stars = 1 )
course[ COURSE_WB ] = StarCount( stars = 23, checkpoints = 4, goal = True, extra = True, has100 = True )
course[ COURSE_WC ] = StarCount( stars = 24, checkpoints = 4, has100 = True )
course[ COURSE_WJ ] = StarCount( stars = 27, checkpoints = 5, goal = True, has100 = True )

empty_line = { "text": "", "Type": 2, }

def gen_desc(mask, offset):
    assert mask <= 255

    return  {
      "text": "",
      "starMask": mask,
      "offset": offset,
      "highlightStarMask": 0,
      "highlightOffset": 0,
      "Type": 1,
      "useExtraIcon": False
    }

def checkpoint_mask(val, off = 7):
    bits = (1 << val) - 1
    return bits << (off - val)

course_descriptions = []
secret_descriptions = []
for i in range(41):
    star_counts = course.get(i, None)
    if star_counts is None:
        continue

    stars = star_counts.stars
    checkpoints = star_counts.checkpoints
    goal = star_counts.goal
    extra = star_counts.extra
    has100 = star_counts.has100

    if checkpoints != 0:
        if checkpoints >= 8:
            assert goal
            course_descriptions.append(gen_desc(255, 16 + i * 8))
            checkpoints = checkpoints - 8
            course_descriptions.append(gen_desc(checkpoint_mask(checkpoints, 8), 16 + i * 8 + 1))
        else:
            mask = checkpoint_mask(checkpoints)
            if goal:
                mask = mask | 128

            course_descriptions.append(gen_desc(mask, 16 + i * 8))
            checkpoints = 0
        
        if has100:
            course_descriptions.append(gen_desc(1, 16 + i * 8 + 1))
    
    off = 16 + i * 8 + 7
    while stars:
        if stars >= 8:
            secret_descriptions.append(gen_desc(255, off))
            stars = stars - 8
        else:
            secret_descriptions.append(gen_desc((1 << stars) - 1, off))
            stars = 0

        off -= 1
    
    while len(course_descriptions) > len(secret_descriptions):
        secret_descriptions.append(empty_line)
    while len(secret_descriptions) > len(course_descriptions):
        course_descriptions.append(empty_line)

jsml = {
  "goldStar": "iVBORw0KGgoAAAANSUhEUgAAABQAAAAUCAYAAACNiR0NAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAAOVSURBVDhPpZJtTJNXFMfr19ZCR0WBMmFMYAbt8K10AmEydct0E7O4ZFs2Mt2LUSfGzEV8iW7TD8vmMj4sQ9zMUEosowLimM0mpuKkuAKVl5RCsGwUqhOetrz05eF5nv8OcLdkkSbT/ZKTe+855//PuTdX9l/gvTs+Gvt92yF2/H9IfqVaCu4ZHHNvG750WraApR8dyZe7G/gECBeirTG5iKUfDa8rWiX6CnqArwEUof92Wt+pY7IYVn54BG7FB8AuQPyeDA8izK2GpV6zj5UfDnTJ5ovjG5zAF2RoIMOjtG6E41ZK34HtMiVrmxtw66ODnrxkfiQnSxjNeVf05peI4wVWSMVkVElG5yhO0P4tTPmz8eedFS1et67EO7TmHZ9Hr/O4spI58pgxC/g2lEl8oV2Y2MkhVARIh0n4GcVpiFPnMOb7lsxKZwzHfDsp9xrVtlJsodgEhJ4Dz+Vxwfv69t72ZWdk9//I2IXwWipSo/QhCb+kdfrNDBh2l+J6Yymmwp9T7hh+tXyF4cE9VHuDzq/S+jIQzIdIbzvYnQpr4+LdM1M625R7/feSqCmH4nUyPUDNJ+DoOgJj+acIBQ7ReT/KS4+g1fom7WlC/nkER7Jw15kO27WFuGRU7p0x+xt7U1Sxzx1HV8gEhJdI9B5uNG3FpnWJCE68TedCZGeqYTJqaZ+PcbcWd+xJsP4Sg7pKeTGz+TetFsXJWdM1JNqM3p6NOHo4DUJ4+r024+PjKbA3L4fgW4WBzifR/LMatRWKk0w+N/0di8rAL6Mpn6V4geJFeoL1tObRNXMxNboao64MOH7T4PKFhd8xWWSCI2k7gOlrk4G4jiIXUkAHkaYSvasw6dFiuDcdXc3xqDqrfp/JIiNOZJwC9LOGoWfAj2rhH0ynqZaAG6B14CkMOVLpg2tQY4gtYbLIiIGnTcBaSEEd/EPpGOhIgLM1Fg6bGj22WLg6EuHqTEZf2+Mwm+JqmSwi84RJrR3SSpokBd0tMfS3FGiolnvNF+WczaJA+40o3L65AE5bAq7WxXdOa2alcyCN5y8S/BlDk3eT0GmNRn2VIlRdEVVuOh+/8nJVama9UXXWXCMP2CxydFlVaLoS5zF+o9cw+YNI/HL9vf5EseWaSjAZVBfOlyXpWekfLhqe0DX8oDRcvzKfbzI/BnNdWjYrPYire2nBzasJDRVn4iM3MWorNVk/1cTV/1i95BWWImSyvwBM83wTc31XJwAAAABJRU5ErkJggg==",
  "darkStar": "iVBORw0KGgoAAAANSUhEUgAAABQAAAAUCAYAAACNiR0NAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAAL1SURBVDhPpZRJTJNRFIXrXoNRExdu2LE1hgDBPWuDKxaMtZS0dGAqacMUoA0BZApji4UChTIUDIIMYQoQUEJiAxsNS6PucGeM0VzPeT5IDDQRPMlL3//+d7937n33r+FfNDs76xodHfXox/+Tz+e7u7i4+BHAz1lZWff08vUVDAatW1tbMjc3J5WVlQ69fD3V1tbeHh8ff39wcCBLS0tSX19/kpGRcUe/vrp6e3ttCwsLEovFZG1tTfAsdrvdqV9fTXV1dTdDodCHvb09OTo6ko2NDRkZGZGqqqqT9PT0W3rb5cLGhEAgkIiROjg4aBoeHu5Eqm/oijA63N7eFty2YI+0tbW97erq6sR41t3dndLe3p44MDCQoGAouh8bY/Pz86es0/r6uuzu7srh4aEC7e/vqzmB0WhUpqenJRKJyMTEhITDYUEWAhOn/f397xoaGgKGlpYWCxZkZmZGVldXhSkSRGebm5sKsrOzo+aETU5OnoORhSAbAUwaGxulrKzMqlxiYm9qahK4PQfT0dTUlLqIlZUVWV5eZqrS09OjHKIvpa+vTxhXUlIieXl5dgU7k8PhcPMUnsaTUQKBe0lOTlaHsA+TkpJ4y8pVR0eH1NTUiM1mk5ycHLfG/K3i4mIvoX6/X0EZlJmZqeYcnBPCQ9GTZzCvDr9cHo/HzzTpgmmNjY2pdhkaGlIlIay1tVXcbreYTKYXOiy+UCcjgwgglBA65hoHWkXwfYvL5aI7sw6LL/TVc946gfzFs3LE4rOmHF6vVzksKCjo1GHxhXSjBNEVQdXV1fxTkIqKCuWKNcRXxC9GioqKXuqwuLqBtogxNToqLy8Xi8XClvgKN6e4NHXLpaWlglqL1Wo9Zsyf0EuEmt1Hip+am5tVb+Xm5n7Pzs4OGY3GR7jRh4AGMb4BpKCAf3E6nQ90+EUh3TS0wy84+YmCR/Lz89P0q3MhzRRAw2az+QfdA/hYv7oo9OATbHgNWPxNWoWFhamAv4Lzp3oJMhh+A6+WOXJp1D3dAAAAAElFTkSuQmCC",
  "starAmount": "1000",
  "starsShown": 8,
  "useEmptyStars": False
}
jsml["courseDescription"] = course_descriptions
jsml["secretDescription"] = secret_descriptions

path = 'd:\\git\\MA2\\layout.jsml'
with open(path, 'w') as f:
    json.dump(jsml, f)
