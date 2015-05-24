
###################################################################################
## b u i l d _ s p r i t e s h e e t s . p y
##
## easier way to define animated sprite sheets by hand for cocos2d-x
## generates the required .plist files for SpriteFrameCache::addSpriteFramesWithFile
## only supports one given size per frame for each sprite-sheet
##
## python 2.5+, python 3.0+


from __future__ import with_statement
import os


###################################################################################
## c o n f i g u r e


# configure sprite sheet animation properties here
# example: ['path/file.name', (img_width, img_height),
# (sprite_width, sprite_height), n_frames],
sprite_sheets = [

	# dev-player
	['res/sprites/dev-player.png', (256, 32), (32, 32), 8],

]


###################################################################################
## c o d e   f u n c t i o n


# generate plist file from given sprite sheet data
def gen_sprite_sheet_plist(p_file, img_siz, spr_siz, s_frames):
	print('file :: %s' % p_file)

	res = plist_start
	res += plist_tex % (img_siz[0], img_siz[1])
	res += plist_frames_start

	i = 1
	x = 0
	y = spr_siz[1]
	base_name = os.path.splitext(os.path.basename(p_file))[0]

	while (x < img_siz[0] and y <= img_siz[1]):
		res += plist_frame % (base_name + '-%s' % i, x, y - spr_siz[1],
			spr_siz[0], spr_siz[1], 0, 0, spr_siz[0], spr_siz[1])
		x += spr_siz[0]
		if x > img_siz[0]: y+= spr_siz[1]
		i += 1

	res += plist_frames_end
	res += plist_end

	try:
		with open(p_file, 'w') as f:
			f.write(res)

	except IOError:
		print('error :: could not write to file %s' % p_file)
		return False

	return True

# generate plist files from sprite_sheets data
def main():
	n_plists = 0
	print('generating plists:')

	for sheet in sprite_sheets:
		if len(sheet) < 4:
			print('error :: bad sprite_sheets config')
			return

		if len(sheet[1]) < 2 or len(sheet[2]) < 2:
			print('error :: bad sprite_sheets config')
			return

		# sheet = ['path/file.name', (img_width, img_height),
		# (sprite_width, sprite_height), n_frames],
		s_file = sheet[0]
		s_img_width = sheet[1][0]
		s_img_height = sheet[1][1]
		s_spr_width = sheet[2][0]
		s_spr_height = sheet[2][1]
		s_frames = sheet[3]

		if type(s_file) == type('') and \
		   isinstance(s_img_width, int) and \
		   isinstance(s_img_height, int) and \
		   isinstance(s_spr_width, int) and \
		   isinstance(s_spr_height, int) and \
		   isinstance(s_frames, int):

			if os.path.isfile(s_file):
				if not gen_sprite_sheet_plist(os.path.splitext(s_file)[0] + \
					'.plist', (s_img_width, s_img_height), \
					(s_spr_width, s_spr_height), s_frames): return
				n_plists += 1

			else:
				print('error :: %s does not exist' % s_file)
				return
		else:
			print('error :: invalid sprite_sheets config')
			return

	print('generated %s plist files successfully' % n_plists)


###################################################################################
## d a t a   t e m p l a t e s


# plist document header template
plist_start = '<?xml version="1.0" encoding="UTF-8"?>\n' + \
  '<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" ' \
  '"http://www.apple.com/DTDs/PropertyList-1.0.dtd">\n' \
  '<plist version="1.0">\n'

# plist texture section template
# plist_tex % (img_width, img_height)
plist_tex = '<dict>\n\t<key>texture</key>\n\t<dict>\n\t\t' + \
	'<key>width</key>\n\t\t<integer>%s</integer>\n\t\t' + \
	'<key>height</key>\n\t\t<integer>%s</integer>\n\t</dict>\n'

# plist frames header template
plist_frames_start = '\t<key>frames</key>\n\t<dict>\n'

# plist frame section template
# plist_frame % (spr_name, spr_start_x, spr_start_y, spr_width, spr_height,
# spr_offset_x, spr_offset_y, spr_original_width, spr_original_height)
plist_frame = '\t\t<key>%s</key>\n\t\t<dict>\n\t\t\t<key>x</key>' + \
	'\n\t\t\t<integer>%s</integer>\n\t\t\t<key>y</key>\n\t\t\t' + \
	'<integer>%s</integer>\n\t\t\t<key>width</key>\n\t\t\t<integer>' + \
	'%s</integer>\n\t\t\t<key>height</key>\n\t\t\t<integer>%s' + \
	'</integer>\n\t\t\t<key>offsetX</key>\n\t\t\t<real>%s' + \
	'</real>\n\t\t\t<key>offsetY</key>\n\t\t\t<real>%s</real>' + \
	'\n\t\t\t<key>originalWidth</key>\n\t\t\t<integer>%s' + \
	'</integer>\n\t\t\t<key>originalHeight</key>\n\t\t\t' + \
	'<integer>%s</integer>\n\t\t</dict>\n'

# plist frames end template
plist_frames_end = '\t</dict>\n'

# plist document end template
plist_end = '</dict>\n</plist>\n'


###################################################################################
## i n i t


if __name__ == '__main__':
	main()
