# This file should contain all the record creation needed to seed the database with its default values.
# The data can then be loaded with the rake db:seed (or created alongside the db with db:setup).
#
# Examples:
#
#   cities = City.create([{ name: 'Chicago' }, { name: 'Copenhagen' }])
#   Mayor.create(name: 'Emanuel', city: cities.first)

def seed_user arg
  arg[:password] = "12345678" unless arg[:password]
  arg[:password_confirmation] = arg[:password]
  arg[:name] = "nobody" unless arg[:name]
  arg[:email] = "nobody@nowhere.com" unless arg[:email]
  u = User.find_or_create_by_name arg
  puts "  user #{arg[:email]}"
  u
end

#u0 = seed_user :name => "admin@btc.com", :email => "admin@btc.com", :password => "adminx", :password_confirmation => "adminx"


User.create!(email: 'admin@example.com', password: 'password', password_confirmation: 'password') 