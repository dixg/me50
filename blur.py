from PIL import Image, ImageFilter

before=Image.open("lena_color.bmp")
before = before.convert('RGB')
after = before.filter(ImageFilter.BLUR)
after.save("final_lenaoutcome.bmp")
