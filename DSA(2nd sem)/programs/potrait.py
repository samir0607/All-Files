from PIL import Image, ImageDraw

# Create a blank canvas
canvas = Image.new("RGB", (400, 600), "white")
draw = ImageDraw.Draw(canvas)

# Draw a simple face
# Head
draw.ellipse((100, 50, 300, 350), fill=(255, 220, 200), outline="black")

# Eyes
draw.ellipse((150, 150, 180, 180), fill="white", outline="black")  # Left eye
draw.ellipse((220, 150, 250, 180), fill="white", outline="black")  # Right eye
draw.ellipse((160, 160, 170, 170), fill="black")  # Left pupil
draw.ellipse((230, 160, 240, 170), fill="black")  # Right pupil

# Mouth
draw.ellipse((180, 260, 220, 280), fill="red", outline="black")  # Upper lip
draw.arc((180, 265, 220, 290), start=0, end=180, fill="red")  # Lower lip

# Nose
draw.polygon([(190, 200), (210, 200), (200, 240)], fill=(255, 220, 200), outline="black")

# Save the portrait
canvas.save("portrait.png")
canvas.show()
