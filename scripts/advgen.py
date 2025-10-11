import json

jsml = None
with open('D:/tools/sd/layout/MARIO ADVENTURE 2.jsml', 'r') as f:
    jsml = json.load(f)
    course_descriptions = jsml["courseDescription"]
    secret_descriptions = jsml["secretDescription"]

adv_groups = []

def adv_data(desc):
    if desc["Type"] == 1 and desc["starMask"] != 0:
        return { "data": [ { "offset": desc["offset"], "mask": desc["starMask"] } ] }

    return None

def adv_groups(descriptions, side, groups):
    group = None
    for desc in descriptions:
        adv_course = adv_data(desc)
        if adv_course:
            if group:
                group["courses"].append(adv_course)
            else:
                # Mind that this act will also push an empty line before it
                # Because both groups first line will be an empty line, it is not a problem
                group = { "name": "", "side": side, "courses": [ adv_course ] }
        else:
            if group:
                # Next group will put an empty line so just finalize this one...
                groups.append(group)
                group = None
            else:
                # ...else push a phony group just for the sake of empty line
                phony_group = { "name": "", "side": side, "courses": [] }
                groups.append(phony_group)

    if group:
        groups.append(group)

groups = []
adv_groups(course_descriptions, "left", groups)
adv_groups(secret_descriptions, "right", groups)

adv = {
    "$schema": "https://parallel-launcher.ca/layout/advanced-01/schema.json",
	"format": {
		"save_type": "SRAM",
		"num_slots": 4,
		"slots_start": 0,
		"slot_size": 504,
		"active_bit": 95,
        "checksum_offset": None
	},
	"groups": groups
}

path = 'd:\\git\\MA2\\layout.json'
with open(path, 'w') as f:
    json.dump(adv, f)
